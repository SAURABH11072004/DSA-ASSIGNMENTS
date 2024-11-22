#include<iostream>
using namespace std;
class node
{
    int id;
    string name;
    int salary;
    public:
    void getdata()
    {
        cout<<"enter id-";
        cin>>id;
        cout<<"enter name-";
        cin>>name;
        cout<<"enter salary-";
        cin>>salary;
    }
    void display()
    {
        cout<<"name-"<<name<<"ID-"<<id<<"SALRY-"<<salary;
    }
    void mergesort(node aa[],int low,int high)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergesort(aa,low,mid);
            mergesort(aa,mid+1,high);
            merge(aa,low,mid,high);
            
        }
    }
    void merge(node aa[],int low,int mid,int high)
    {
        int i=low;
        int j=mid+1;
        int k=low;
        node *b=new node[high+1];
        while(i<=mid && j<=high)
        {
            if(aa[i].name <=aa[j].name){
                b[k]=aa[i];
                i++;
                k++;
            }
            else{
                b[k]=aa[j];
                j++;
                k++;
            }
        }
        while(i<=mid)
        {
            b[k]=aa[i];
            i++;k++;
        }
        while(j<=high)
        {
            b[k]=aa[i];
            j++;k++;
        }
    }
    void swap(node& a,node& b)
    {
        node temp=a;
        a=b;
        b=temp;
    }
    void quick(node aa[],int low,int high)
    {
        if(low<high){
        int j=partition(aa,low,high);
        quick(aa,low,j-1);
        quick(aa,j+1,high);
    }}
    int partition(node aa[],int low,int high)
    {
        int i=low+1;
        int j=high;
        int pivot=aa[low].id;
        while(i<=j)
        {
           while(i<=high && aa[i].id <= pivot)
           {
               i++;
           }
           while(j>=low && aa[j].id>pivot)
           {
               j--;
           }
           if(i<j)
           {
               swap(aa[i],aa[j]);
           }
           
        }
        swap(aa[low],aa[j]);
        return j;
    }
    
};
int main()
{
    node ad;
    int choice;
    int n;
    cout<<"enter no of employees-";
    cin>>n;
    node aa[n];
    do{
        cout<<"\n1.add data-\n2.show data\n3.merge\n4.quick\n";
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
                aa[i].display();
            }
            break;
            case 3:
            ad.mergesort(aa,0,n-1);
            for(int i=0;i<n;i++)
            {
                aa[i].display();
            }
            break;
            case 4:
            ad.quick(aa,0,n-1);
            for(int i=0;i<n;i++)
            {
                cout<<"\n";
                aa[i].display();
            }
            break;
        }
        
    }while(choice!=4);
    return 0;
}
