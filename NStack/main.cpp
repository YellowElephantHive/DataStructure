#include <iostream>
#include "NStack.hpp"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	NStack ns = NStack(10);
	int val, option, rm_val;
	while(ns.isFull()==false||val==-1){
		std::cout << "Input a positive integer (-1 to end):";
		std::cin >> val;
		
		if(val == -1)
			break;
			
		else
		    ns.Push(val);
		
	}
	
	while(option != 4){
	
		std::cout << "Option:1)Output. 2)Remove. 3)Sort. 4)Quit: ";
		std::cin >> option;
		switch(option){
			case 1:
				ns.Output(ns);
				std::cout << std::endl;
				break;
			
			case 2:
				std::cout << "Number to remove: ";
				std::cin >> rm_val;
				if(ns.Remove(ns, rm_val)==true)
					std::cout << rm_val << " is deleted!" << std::endl;
				else
					std::cout << "not found!" << std::endl;
				break;
				
			case 3:
				ns.Sort(ns);
				std::cout << std::endl;
				break;
		}
	}
	//system("pause");
	return 0;
}
