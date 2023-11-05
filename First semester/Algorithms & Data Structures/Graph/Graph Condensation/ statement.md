# Graph Condensation

You are given a directed graph with N vertices and M edges (1 ≤ N ≤ 200000, 1 ≤ M ≤ 200000).
Find the strongly connected components of the given graph and topologically sort its condensation.

#### Input

The graph is described in the input file as follows: the first line contains the numbers N and M. Each of the following M lines contains a description of an edge – two integers from the range from 1 to N – the start and end vertices of the edge.

#### Output

On the first line, output the number K – the number of strongly connected components in the given graph. On the next line, output N numbers – for each vertex, output the number of the strongly connected component to which it belongs. The strongly connected components should be numbered in such a way that for any edge, the number of the strongly connected component of its start does not exceed the number of the strongly connected component of its end.
