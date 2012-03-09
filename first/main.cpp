
#include <iostream>
#include <fstream>
#include "Wrapper.h"
#include <utility>

int main (int argc, char* argv[]){

	//std::fstream infile ("input.txt", std::fstream::in);
	//std::fstream outfile ("output.txt", std::fstream::out);
	if (argc == 4)
	{
		int num = atoi(argv[3]);
		Wrapper<std::pair<int, int> > helper(0, num);
		std::pair<int, int> p;

		p.first = atoi(argv[1]);
		p.second = atoi(argv[2]);
		
		
		helper.run(p);
	}
	else if (argc == 3)
	{	
		int num = atoi(argv[2]);
		Wrapper<int> helper(1, num);
		int argum = atoi(argv[1]); 
		helper.run(argum);
	}
	else {
		std::cerr << "not enought arguments" << std::endl;
		exit(1);
	}
	int x, n;

	//infile >> x >> n;
	
	

	//Executer<int> exec(n);
/*	MyFunction myFunc;		//тут тип должен совпадать с типом, который передается Tester
	Tester<int> myTester(x, n, &myFunc);//обобщен.

	std::vector<int> resVect = exec.run(x);
	std::cout << "Loop lenght: " << resVect[0] << std::endl;
	std::cout << "Tail lenght:  " << resVect[1] << std::endl;
	std::cout << "Is everything right: ";
	if ( myTester.run(resVect))
	{
		std::cout << "yes";	
	}
	else 
		std::cout << "no";
 	std::cout<< std::endl;
*/	
	return 0;
}
