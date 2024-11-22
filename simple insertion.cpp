#include<iostream>
using namespace std;
class node
{
    int roll; 
    string name;
    float cgpa;
    public:
    void getdata()
    {
        cout<<"enter student name-";
        cin>>name;
        cout<<"enter student roll_no";
        cin>>roll;
        cout<<"enter student cgpa";
        cin>>cgpa;
    }
    void display(){
        cout<<"Name"<<name<<endl<<"Roll"<<roll<<endl<<"cgpa"<<cgpa<<endl;
    }
    void insertion(node aa[],int n)
    {
        for(int i=1;i<n;i++)
        {
            node temp=aa[i];
            int j=i-1;
            while(j>=0 && aa[j].roll > temp.roll){
                aa[j+1]=aa[j];
                j--;
            }
            aa[j+1]=temp;
        }
    }
   
};
int main()
{
    node ad;
    int n;
    int choice;
    cout<<"enter no of students-";
    cin>>n;
    node aa[n];
    do{
        
        cout<<"\n1.add data\n2.show data\n3.sort by roll using insertion\n";
        cout<<"enter choice-";
        cin>>choice;
        switch(choice)
        {
            case 1:
            
            for(int i=0;i<n;i++)
            {
                aa[i].getdata();
            }
            break;
            case 2:
            for(int i=0;i<n;i++)
            {
                cout<<endl;
                aa[i].display();
            }
            break;
            case 3:
            ad.insertion(aa,n);
            for(int i=0;i<n;i++)
            {
                cout<<endl;
                aa[i].display();
            }
            break;
            default:
            cout<<"invbalid"<<endl;
            break;
        }
    }while(choice!=4);
    return 0;
}
