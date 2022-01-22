//
//  main.cpp
//  DBCircularLinkedList
//
//  Created by ПрЈ|Т@ on 2021/12/5.
//

#include <iostream>
#include "DBCircularLinkedList.hpp"
#include "DBCircularLinkedList.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "1) InsertFront" << endl;
    cout << "2) InsertBack" << endl;
    cout << "3) Delete" << endl;
    cout << "4) IteratorFront" << endl;
    cout << "5) IteratorBack" << endl;
    cout << "6) Display" << endl;
    cout << "7) Copy" << endl;
    cout << "-1) Exit" << endl;
    
    int val;
    int option = 0;
    CircularChain<int> list = CircularChain<int>();
    CircularChain<int> copylist;
    while (option!=-1) {
        cin >> option;
        switch (option) {
            case 1:
            	cout << "Insert at the front" << endl;
                cin >> val;
                list.InsertFront(val);
                break;
                
            case 2:
            	cout << "Insert at the back" << endl;
            	cin >> val;
            	list.InsertBack(val);
            	break;
            	
            case 3:
            	cout << "Delete the value" << endl;
            	cin >> val;
            	list.Delete(val);
            	cout << val << " is deleted" << endl;
            	break;
            	
            case 4:
            	cout << "Interate towards the front" << endl;
            	list.IteratorFront();
            	cout << "" << endl;
            	break;
            	
            case 5:
            	cout << "Interate towards the back" << endl;
            	list.IteratorBack();
            	cout << "" << endl;
            	break;
                
            case 6:
            	list.Display();
            	cout << "" << endl;
            	break;
            	
            case 7:
            	cout << "Copy list" << endl;
            	copylist = list;
            	copylist.Display();
            	cout << "" << endl;
            	break;
            
			case -1:
				cout << "Exit" << endl;
				exit(0);
			    break;
            
            default:
                break;
        }
    }
    
    return 0;
}

