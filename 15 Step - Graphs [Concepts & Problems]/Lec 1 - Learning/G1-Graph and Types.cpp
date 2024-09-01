/*

📍 Introduction to Graph
 📌What is a graph data structure?
 📌There are two types of data structures

 📍Linear and Non - linear
We are aware of linear data structures such as arrays, stacks, queues, and linked lists. They are called linear because data elements are arranged in a linear or sequential manner.

The only non-linear data structure that we’ve seen so far is Tree. In fact, a tree is a special type of graph with some restrictions. Graphs are data structures that have a wide-ranging application in real life. These include analysis of electrical circuits, finding the shortest routes between two places, building navigation systems like Google Maps, even social media using graphs to store data about each user, etc. To understand and use the graph data structure, let’s get familiar with the definitions and terms associated with graphs.

📍Definitions and Terminology
A graph is a non-linear data structure consisting of nodes that have data and are connected to other nodes through edges.

Nodes are circles represented by numbers. Nodes are also referred to as vertices. They store the data. The numbering of the nodes can be done in any order, no specific order needs to be followed.

In the following example, the number of nodes or vertices = 5

Two nodes are connected by a horizontal line called Edge. Edge can be directed or undirected. Basically, pairs of vertices are called edges.

In the above example, the edge can go from 1 to 4 or from 4 to 1, i.e. a bidirectional edge can be in both directions, hence called an undirected edge. Thus, the pairs (1,4) and (4,1) represent the same edge.

📌 Types of Graphs
An undirected graph is a graph where edges are bidirectional, with no direction associated with them, i.e, there will be an undirected edge. In an undirected graph, the pair of vertices representing any edge is unordered. Thus, the pairs (u, v) and (v, u) represent the same edge.
A directed graph is a graph where all the edges are directed from one vertex to another, i.e, there will be a directed edge. It contains an ordered pair of vertices. It implies each edge is represented by a directed pair <u, v>. Therefore, <u, v> and <v, u> represent two different edges.
There can be multi-directed edges, hence bidirectional edges, as shown in the example below.


📌 Structure of Graph
Does every graph have a cycle?
More read refer for takeuforward website.


📍Property: It states that the total degree of a graph is equal to twice the number of edges. This is because every edge is associated/ connected to two nodes.
Total Degree of a graph = 2 x E
Example, (2+2+3+2+3) = 2 x 6 => 12 = 12

For directed graphs, we’ve Indegree and Outdegree. The indegree of a node is the number of incoming edges. The outdegree of a node is the number of outgoing edges.

📍 Edge Weight
A graph may have weights assigned on its edges. It is often referred to as the cost of the edge.

If weights are not assigned then we assume the unit weight, i.e, 1. In applications, weight may be a measure of the cost of a route. For example, if vertices A and B represent towns in a road network, then weight on edge AB may represent the cost of moving from A to B, or vice versa.

*/