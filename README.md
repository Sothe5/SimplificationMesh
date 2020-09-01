# SimplificationMesh

Most of this code does not belong to me. It belongs to Dr.Hamish Carr lecturer at the University of Leed which gave us this files as templates.

Our task was to modify them to be able to have a final application to do the following: when moving an slider made with QT which indicates
the percentage of simplification of a mesh we need to delete vertices to perform the simplification of the mesh.

My personal code are the functions DeleteVertex(), get1RingSize(), getNeighbours() and fillQueue(). All of them are in the file GeometricSurfaceDirectedEdge.cpp

Also, I modified the file GeometricController.cpp to be able to implement the removal of the vertices depending on the values of the slider.

Our policy to select which vertex will be the next to be removed is, removing first the vertices with a higher number of neighbours.

# To Compile:

For linux machines download and install QT and execute ./compile.sh it is a file I created to execute all the commands to compile

To execute the compiled files use: ./nameFolder ./diredgenormals/fileName.diredgenormal
