#!/bin/bash

if ! type "aws" > /dev/null;
then
       	echo "aws cli is not installed. Please install and configure it first."
       	exit 1	
fi

echo "Fetching running EC2 instances.."

if [ -z "$1" ]; then
    echo "Usage: $0 <aws-profile>."
    exit 1
fi

profile_name=$1

aws ec2 describe-instances --filters "Name=instance-state-name,Values=running" \
  --query "Reservations[*].Instances[*].{ID:InstanceId,Type:InstanceType,State:State.Name}" \
  --profile "$profile_name" --output table

read -p "Enter the instance id: " instance_id

instances=$(aws ec2 describe-instances --filters "Name=instance-state-name,Values=running" \
  --query "Reservations[*].Instances[*].[InstanceId,PublicDnsName]" \
  --profile "$profile_name" --output text)

instance_address=$(echo "$instances" | awk -v id="$instance_id" '$1 == id { print $2 }')

echo "Connecting to Instance $instance_id at address: $instance_address"
ssh -o IdentitiesOnly=yes -i "~/.ssh/epic-hw2-key.pem" ubuntu@${instance_address} "nginx -v; docker -v"

if [ $? -ne 0 ]; then
    echo "Error occurred when connecting to EC2 instance. Check your SSH key, instance ID, and network settings."
    exit 1
fi
echo "Verification complete."


