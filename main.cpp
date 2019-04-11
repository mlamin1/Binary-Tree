#include <iostream>
#include "BinaryTree.h"
#include <stdlib.h>
#include <chrono>
#include <algorithm>

//Muniru Lamin
//COSC320 Lab-8
//04/10/19
using namespace std;
int main()
{
	srand(time(0));
	BinaryTree X;
	int option1;
	do{

		std::cout << "***************************" << std::endl;
		std::cout << "***************************" << std::endl;
		std::cout << "***************************" << std::endl;
		std::cout << "Program type Menu Option" << std::endl;
		std::cout << "input 1 to run the test program" << std::endl;
		std::cout << "input 2 to run program where user input numbers in tree" << std::endl;
		std::cout << "Input 3 to end the Entire program: ";
		std::cin >> option1;
		if(option1 == 1)
		{
			int option;
			do{
				std::cout << "***************************" << std::endl;
				std::cout << "***************************" << std::endl;
				std::cout << "***************************" << std::endl;
				std::cout << "Binary Tree input menu" << std::endl;
				std::cout << "input 1 to insert into the tree" << std::endl;
				std::cout << "input 2 to Search for a node " << std::endl;
				std::cout << "input 3 to find the min of the tree" << std::endl;
				std::cout << "input 4 to find the max of the tree" << std::endl;
				std::cout << "input 5 to find the Successor of a number in tree" << std::endl;
				std::cout << "input 6 to Print the tree Inorder" << std::endl;
				std::cout << "input 7 to Delete a number from the tree" << std::endl;
				std::cout << "Input 8 to Print the tree in a Unique format." << std::endl;
				std::cout << "input 9 to end program: ";
				std::cin >> option;

				if(option == 1)
				{
					std::cout << "The tree will be randomly filled with values" << std::endl;
					int treesize;
					std::cout<< "Input the number of Items to be put into the tree: ";
					std::cin >> treesize;

					auto start = std::chrono::system_clock::now();
					for(int i = 0; i < treesize; i++)
					{
						X.InsertTree(rand() % treesize + 1);
					}
					auto end = std::chrono::system_clock::now();
					std::chrono::duration<double> elapsed_seconds = end-start;
					std::time_t end_time = std::chrono::system_clock::to_time_t(end);
					std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";

					std::cout << "Done inserting " << treesize << " items into the tree randomly range: 1 - " << treesize << std::endl;
				}else if(option == 2)
				{
					std::string again;
					do{
						int search;
						std::cout << "Input the number you would like to search in the tree for: ";
						std::cin >> search;

						//if(X.searchTree(search))
						if(X.searchTree(search))
						{
							auto start = std::chrono::system_clock::now();
							X.searchTree(search);	
							auto end = std::chrono::system_clock::now();
							std::chrono::duration<double> elapsed_seconds = end-start;
							std::time_t end_time = std::chrono::system_clock::to_time_t(end);
							std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";

							std::cout<< search << " is in the tree" << std::endl;
						}
						else{
							std::cout << search << " is not in the tree" << std::endl;
						}
						std::cout << "Would you like to search for another number input Y or N: ";
						std::cin >> again;
					}while(again == "y" || again == "Y");
				}else if(option == 3)
				{
					std::cout << "********************************" << std::endl;
					std::cout << "*	    	Tree MIN	*" << std::endl;
					std::cout << "********************************" << std::endl;
					std::cout << X.minTree() << " is the minimum value in the Tree" << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}else if(option == 4)
				{
					std::cout << "********************************" << std::endl;
					std::cout << "*	    	Tree MAX	*" << std::endl;
					std::cout << "********************************" << std::endl;
					std::cout << X.maxTree() << " is the maximum value in the tree" << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}else if(option == 5)
				{
					std::string again;
					do{
						X.Print();
						int suc;
						std::cout << "Input the number you would like to find the successor for: ";
						std::cin >> suc;
						if(X.SuccessorNode(suc) == -1)
						{
							std::cout << "The value is not in the tree!! " << std::endl;
						}
						else if(X.SuccessorNode(suc) == suc)
						{
							std::cout << suc << " is the max value in the tree, it does not have a successor. " << std::endl;
						}
						else
							std::cout <<X.SuccessorNode(suc) << " is the successor of " << suc <<std::endl;	

						std::cout << "Would you like to find another successor? Input Y or N: ";
						std::cin >> again;
					}while(again == "y" || again == "Y");
				}else if(option == 6)
				{
					std::cout << "********************************" << std::endl;
					std::cout << "*	  Tree Inorder Print	*" << std::endl;
					std::cout << "********************************" << std::endl;
					std::cout << std::endl;
					X.PrintInorder();
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}else if(option == 7)
				{
					std::string again;
					do{
						X.Print();
						int del;
						std::cout << "input number to be deleted: ";
						std::cin >> del;
						if(X.searchTree(del))
						{
							auto start = std::chrono::system_clock::now();
							std::cout << X.DeleteTree(del) << " has been deleted" << std::endl;
							auto end = std::chrono::system_clock::now();
							std::chrono::duration<double> elapsed_seconds = end-start;
							std::time_t end_time = std::chrono::system_clock::to_time_t(end);
							std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
						}
						else{
							std::cout << del << " is not in the tree " << std::endl;
						}
						std::cout << "Would you like to delete another number input Y or N: ";
						std::cin >> again;
					}while(again == "y" || again == "Y");
				}else if(option == 8)
				{

					std::cout << "********************************" << std::endl;
					std::cout << "*	    Formated Print	*" << std::endl;
					std::cout << "********************************" << std::endl;
					X.Print();
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}

			}while(option != 9);
		}



		else if(option1 == 2)
		{

			BinaryTree Y;
			/***************************************************************************************/
			//											/
			//		User Input values into trees and test functions				/
			//											/
			/***************************************************************************************/
			int option;
			do{
				std::cout << "***************************" << std::endl;
				std::cout << "***************************" << std::endl;
				std::cout << "***************************" << std::endl;
				std::cout << "Binary Tree input menu" << std::endl;
				std::cout << "input 1 to insert into the tree" << std::endl;
				std::cout << "input 2 to Search for a node " << std::endl;
				std::cout << "input 3 to find the min of the tree" << std::endl;
				std::cout << "input 4 to find the max of the tree" << std::endl;
				std::cout << "input 5 to find the Successor of a number in tree" << std::endl;
				std::cout << "input 6 to Print the tree Inorder" << std::endl;
				std::cout << "input 7 to Delete a number from the tree" << std::endl;
				std::cout << "Input 8 to Print the tree in a Unique format." << std::endl;
				std::cout << "input 9 to end program: ";
				std::cin >> option;

				if(option == 1)
				{

					int treesize;
					std::cout<< "Input the number of Items to be put into the tree: ";
					std::cin >> treesize;

					std::cout << "input " <<treesize << " numbers into the tree: " << std::endl;
					int input;
					for(int i = 0; i < treesize; i++)
					{
						std::cout << "# " << i << ": ";
						std::cin >> input;
						Y.InsertTree(input);
					}

				}else if(option == 2)
				{
					std::string again;
					do{
						int search;
						std::cout << "Input the number you would like to search in the tree for: ";
						std::cin >> search;

						//if(X.searchTree(search))
						if(Y.searchTree(search))
						{
							auto start = std::chrono::system_clock::now();
							Y.searchTree(search);	
							auto end = std::chrono::system_clock::now();
							std::chrono::duration<double> elapsed_seconds = end-start;
							std::time_t end_time = std::chrono::system_clock::to_time_t(end);
							std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";

							std::cout<< search << " is in the tree" << std::endl;
						}
						else{
							std::cout << search << " is not in the tree" << std::endl;
						}
						std::cout << "Would you like to search for another number input Y or N: ";
						std::cin >> again;
					}while(again == "y" || again == "Y");
				}else if(option == 3)
				{
					std::cout << "********************************" << std::endl;
					std::cout << "*	    	Tree MIN	*" << std::endl;
					std::cout << "********************************" << std::endl;
					std::cout << Y.minTree() << " is the minimum value in the Tree" << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}else if(option == 4)
				{
					std::cout << "********************************" << std::endl;
					std::cout << "*	    	Tree MAX	*" << std::endl;
					std::cout << "********************************" << std::endl;
					std::cout << Y.maxTree() << " is the maximum value in the tree" << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}else if(option == 5)
				{
					std::string again;
					do{
						Y.Print();
						int suc;
						std::cout << "Input the number you would like to find the successor for: ";
						std::cin >> suc;
						if(Y.SuccessorNode(suc) == -1)
						{
							std::cout << "The value is not in the tree!! " << std::endl;
						}
						else if(Y.SuccessorNode(suc) == suc)
						{
							std::cout << suc << " is the max value in the tree, it does not have a successor. " << std::endl;
						}
						else
							std::cout << Y.SuccessorNode(suc) << " is the successor of " << suc <<std::endl;	

						std::cout << "Would you like to find another successor? Input Y or N: ";
						std::cin >> again;
					}while(again == "y" || again == "Y");
				}else if(option == 6)
				{
					std::cout << "********************************" << std::endl;
					std::cout << "*	  Tree Inorder Print	*" << std::endl;
					std::cout << "********************************" << std::endl;
					std::cout << std::endl;
					Y.PrintInorder();
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}else if(option == 7)
				{
					std::string again;
					do{
						Y.Print();
						int del;
						std::cout << "input number to be deleted: ";
						std::cin >> del;
						if(Y.searchTree(del))
						{
							auto start = std::chrono::system_clock::now();
							std::cout << Y.DeleteTree(del) << " has been deleted" << std::endl;
							auto end = std::chrono::system_clock::now();
							std::chrono::duration<double> elapsed_seconds = end-start;
							std::time_t end_time = std::chrono::system_clock::to_time_t(end);
							std::cout << "finished at " << std::ctime(&end_time) << "elapsed time: " << elapsed_seconds.count() << "s\n";
						}
						else{
							std::cout << del << " is not in the tree " << std::endl;
						}
						std::cout << "Would you like to delete another number input Y or N: ";
						std::cin >> again;
					}while(again == "y" || again == "Y");
				}else if(option == 8)
				{

					std::cout << "********************************" << std::endl;
					std::cout << "*	    Formated Print	*" << std::endl;
					std::cout << "********************************" << std::endl;
					Y.Print();
					std::cout << std::endl;
					std::cout << std::endl;
					std::cout << std::endl;
				}

			}while(option != 9);

		}


	}while(option1 != 3);
	std::cout << std::endl;
	std::cout << "END OF PROGRAM,THANK YOU!!! BYE!!!" << std::endl;
	return 0;
}
