#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <iostream>
using namespace std;

void hanoi(int n_disks, char tower_1, char tower_2, char tower_3){
    if(n_disks==1){
        cout<<"Move disk "<<n_disks<<" from "<<tower_1<<" to "<<tower_3<<endl;
    }
    else{
        hanoi(n_disks-1,tower_1,tower_3,tower_2);
        cout<<"Move disk "<<n_disks<<" from "<<tower_1<<" to "<<tower_3<<endl;
        hanoi(n_disks-1,tower_2,tower_1,tower_3);
    
        
    }
}
int main(int argc, char *argv[]) {
    int disks;
    cin>>disks;
    hanoi(disks,'1','2','3');
    cout<< endl;
    system("pause");
    return 0;
    
    
}

