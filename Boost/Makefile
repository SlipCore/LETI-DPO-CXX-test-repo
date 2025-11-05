all: asio_server serializer any mpl fusion graph


asio_server: asio.cpp
	g++ asio.cpp -std=c++17 -pthread -o asio_server

serializer: serialization.cpp
	g++ serialization.cpp -lboost_serialization -std=c++17 -o serializer

any: any.cpp
	g++ any.cpp -std=c++17 -o any

mpl: mpl.cpp
	g++ mpl.cpp -std=c++17 -o mpl

fusion: fusion.cpp
	g++ fusion.cpp -std=c++17 -o fusion

graph: graph.cpp
	g++ graph.cpp -std=c++17 -o graph
