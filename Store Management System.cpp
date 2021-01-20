//End Semester OOP project 
//MUSIC STORE 

#include <iostream>
#include <conio.h>
#include <string.h>
#include <cmath>
#include <fstream>

using namespace std; 

int i,n;
ifstream fin;
ofstream fout;
fstream fio;

void disp();

class stock {
        char name [20], pass[10];
        float pr;
        int quant; 

    public:
        void get();
        void get2();
        void show();
        int stchk(char nm[30]);
        void withd(int qty);
        void refil(int qty);

}st;

void stock::withd(int qty){
        if (quant >= qty){
            quant -= qty;
            cout<<"\n\nStock updated.\n";
            cout<<"\n\nTotal Price to be paid:"<<pr*qty;
        }
        else 
            cout<<"\n\nInsufficient Stock";
            getch();
}

void stock::refil(int qty){
        quant += qty;
        cout<<"\n\nStock Updated. ";
        getch();
}

int stock::stchk(char nm[30]){
        if(strcmp(nm,name)==0){
            return 0;
        }
        else 
            return 1;
}

void stock::get(){
    cin>>name>>pr>>quant;

    //*REVIEW HERE 
}

void stock::get2(){
    cin>>name>>quant;
}

void stock::show(){
    cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}

void addnew(){
    system("cls");
    disp();
    getch();
    system("cls");

    cout<<endl;

    cout<<"Enter the number of products that you wish to add: ";
    cin>>n;

    if (n!=0){
        int k,l,sum=0;
        fout.open("Shop.txt", ios::binary|ios::app);
        for(i=0;i<n;i++){
            cout<<endl;
            cout<<"\nInput the name, price and the quantity of the item"<<endl<<endl;
            st.get();
            fout.write((char*)&st,sizeof(st));
            cout<<endl;
            cout<<"\nItem Updated";
            cin.get();

        }
        cout<<endl;
        cout<<"\nStock Updated!";

        fout.close();
        cin.get();
        system("cls");
        disp();
    }
    else{
        fout.close();
        cin.get();
        system("cls");
        cout<<endl;
        cout<<"\nNo items to be added!";
    }
}

void withdraw(){
    system("cls");
    char temp[100]; int qty;
    int i=0;
    long pos=0;
    disp();
    cout<<endl;
    cout<<"\nEnter the Products name: "<<endl;
    cin>>temp;
    cout<<"\n\nEnter Quantity: \n"<<endl;
    cin>>qty;
    fio.open("shop.txt", ios::binary|ios::out|ios::in);
    while(fio){
        pos=fio.tellp();
        fio.read((char*)&st,sizeof(st));
        if(st.stchk(temp)==0){
            st.withd(qty);
            fio.seekp(pos);
            fio.write((char*)&st,sizeof(st));
            i++;break;
        }
    }

    if (i!=1)
        cout<<"\n\nRecord not found!";
     fio.close();
    cin.get();
    system("cls");
    disp();
    getch();
}

void disp(){
    int i=1;
    cout<<"\n -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    cout<<endl<<endl;
    cout<<"-=-=-=-=-\tThe Stock Items are\t-=-=-";
    cout<<endl<<endl;
    cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n";
    cout<<"\n\n Particulars\tStock Available\t\t\t Price";
     fin.open("shop.txt",ios::binary);
     while (!fin.eof()){
         fin.read((char*)&st, sizeof(st));
         if(!fin.eof()){
             if(fin.tellg()<0){
                 i=0;break;
             }
             st.show();
         }
     }
     if(i==0){
         cout<<endl<<endl;
         cout<<"\t\t\tEmpty record room!!";
         getch();
     }
     fin.close();

}

void refill(){
    system("cls");
    char temp[100]; int qty;
    int i=0;
    long pos=0;
    disp();

    cout<<endl<<endl;
    cout<<"Enter the products name: ";
    cin>>temp;
    cout<<endl;
    cout<<"Enter quantity: ";
    cin>>qty;
    cout<<endl;
    fio.open("shop.txt",ios::binary|ios::out|ios::in);
    while(fio){
        pos=fio.tellp();
        fio.read((char*)&st,sizeof(st));
        if(st.stchk(temp)==0){
            st.refil(qty);
            fio.seekp(pos);
            fio.write((char*)&st,sizeof(st));
            i++;break;
        }
    }
    if(i!=1)
        cout<<"\n\nRecord Not found!";
     fio.close();
    system("cls");
     disp(); cin.get();

}

void remove(){
    system("cls");
    int i=0;
    char temp[30];
    cout<<endl<<endl;
    cout<<"\t\t\t\tDelete Record"<<endl;
    cout<<endl;
    cout<<"Enter the name of the product: ";
    cin>>temp;
    fout.open("temp.txt", ios::binary);
    fin.open("shop.txt", ios::binary);
    while(!fin.eof()){
        fin.read((char*)&st,sizeof(st));
        if(!fin.eof()){
            if(st.stchk(temp)==0){
                st.show();
                cout<<"\n\n\t\tRECORD DELETED";
                i++;
            }
            else 
                fout.write((char*)&st,sizeof(st));
        }
    }
    if(i==0)
        cout<<"\n\nRecord not found!";
        fin.close();
        fout.close();
        remove("shop.txt");
        rename("temp.txt","shop.txt");

}
int main(){
    char pass[10],pass2[10];
    int i, j;
    cout<<"\t\t\t\t WELCOME TO MUSIC STORE MANAGEMENT SYSTEM";
    cout<<endl<<endl;
    cout<<"1. Dealer Menu"<<endl<<"2. Customer Menu"<<endl<<"3. Employ Menu"<<endl;
    cout<<endl;
    cout<<"Enter your choice: ";
    cin>>j;
    if(j==1){
        system("cls");
        cout<<endl<<"Enter password letter by letter: ";
        for (int z=0; z<3; z++){
            pass[z]=getch();
            system("cls");
            cout<<endl<<"Enter password letter by letter: ";
            for (i=1; i<=(z+1);i++){
                cout<<"*";
            }
        }
        if(strcmp(pass,"OOP")==0){
            system("cls");
            dealermenu:
            system("cls");
            cout<<endl<<"\t\t\tDEALER MENU"<<endl;
            cout<<endl;
            cout<<"1. Add a New Product"<<endl<<"2. Display Stock"<<endl<<"3. Refill"<<endl<<"4. Remove an Item"<<endl<<"5. Exit";
            cout<<endl;
            cout<<"Enter your choice: ";
            cin>>i;
            if(i==1){
                addnew();getch();
            goto dealermenu;
            }
            else if (i==2){
                system("cls");
                disp();getch();
                goto dealermenu;
            }
            else if(i==3){
                refill();
                goto dealermenu;
            }
            else if(i==4){
                remove();
                getch();
                goto dealermenu;
            }
            else {
                system("cls");
                cout<<"\t\t\t System Created by Rana Muneeb Asad & Aitzaz Ahsan"<<endl;
                getch();
                exit(0);
            }
        } 
        else {
        cout<<endl<<"Authorized Personnel Only"<<endl;
        getch();
        exit(0);
        }
    }
    if (j==2){
            custmenu:
        system("cls");
        cout<<endl;
        cout<<"\t\t\t CUSTOMER MENU"<<endl;
        cout<<endl;
        cout<<"1. Purchase"<<endl<<"2. Display stock"<<endl<<"3. Exit"<<endl;
        cout<<endl<<"Enter your choice: ";
        cin>>i;
        if(i==1){
            withdraw();
            getch();
            goto custmenu;
        }
        else if (i==2){
            system("cls");
            disp();
            getch();
            goto custmenu;
        }
        else {
                system("cls");
            cout<<"\t\t\t System Created by Rana Muneeb Asad & Aitzaz Ahsan"<<endl;
            getch();
            exit(0);
        }
    }
    if(j==3){
        system("cls");
        cout<<endl<<endl;
        cout<<"Enter the Password letter by letter: ";
         for (int z=0; z<3; z++){
            pass2[z]=getch();
            system("cls");
            cout<<endl<<endl;
            cout<<"Enter the Password letter by letter: ";
         for(i=1;i<=(z+1);i++){
            cout<<"*";
            }
        }
        if(strcmp(pass2,"emp")==0){
            empmenu:
        system("cls");
        cout<<endl<<endl;
        cout<<"\t\t\t EMPLOYEE MENU"<<endl;
        cout<<"1. Display Stock"<<endl<<"2. Refill"<<endl<<"3. Exit"<<endl;
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>i;
        if(i==1){
                system("cls");
            disp();
            getch();
            goto empmenu;
        }
        else if(i==2){
            refill();
            goto empmenu;
        }
        else{
            system("cls");
             cout<<"\t\t\t System Created by Rana Muneeb Asad & Aitzaz Ahsan"<<endl;
                getch();
                exit(0);
        }
    }
    
}
else{
        cout<<endl<<"Access denied!"<<endl;
        getch();
        exit(0);
    }

getch();

}