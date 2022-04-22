gp: main.cpp
	g++ utilities.cc graph.cc floyd.cc dfs.cc main.cpp -o gp
	# ./gp Example-edges.txt Example-dates.txt commands-Example.txt
	./gp cit-HepPh.txt cit-HepPh-dates.txt commands-HepPh.txt