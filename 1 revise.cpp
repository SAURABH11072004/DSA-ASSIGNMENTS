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
    void shell(node aa[],int n)
    {
        int gap;
        for(gap=n/2;gap>=1;gap=gap/2)
        {
            for(int i=gap;i<n;i++)
            {
                node temp=aa[i];
                 int j=i-gap;
                while(j>=0 && aa[j].name >temp.name)
                {
                    aa[j+gap]=aa[j];
                    j=j-gap;
                }
                aa[j+gap]=temp;
            }
        }
    }
int getmax(node aa[], int n) {
        int max = aa[0].roll;
        for (int i = 1; i < n; i++) {
            if (aa[i].roll > max) {
                max = aa[i].roll;
            }
        }
        return max;
    }

    // Function for radix sort
 void radix(node aa[], int n) {
        int max = getmax(aa, n);
        for (int pos = 1; max / pos > 0; pos *= 10) {
            count(aa, n, pos);
        }
    }

    // Helper function for counting sort based on a specific digit
     void count(node aa[], int n, int pos) {
        node *b=new node[n];           // Temporary array for sorted output
        int count[10] = {0}; // Count array for digits 0-9

        // Count occurrences of each digit
        for (int i = 0; i < n; i++) {
            int digit = (aa[i].roll / pos) % 10;
            count[digit]++;
        }

        // Compute prefix sums for stable sorting
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the sorted array
        for (int i = n - 1; i >= 0; i--) {
            int digit = (aa[i].roll / pos) % 10;
          
           b[--count[digit]]=aa[i];

        }

        // Copy sorted elements back into the original array
        for (int i = 0; i < n; i++) {
            aa[i] = b[i];
        }
        delete[] b;
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
        
        cout<<"\n1.add data\n2.show data\n3.sort by roll using insertion\n4.by shell\n5.radix\n";
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
            case 4:
            ad.shell(aa,n);
            for(int i=0;i<n;i++)
            {
                cout<<endl;
                aa[i].display();
            }
            break;
            case 5:
            ad.radix(aa,n);
            for(int i=0;i<n;i++)
            {
                cout<<endl;
                aa[i].display();
            }
            cout<<"endl";
            for(int i=n-1;i>=0;i--)
            aa[i].display();
            break;
            default:
            cout<<"invbalid"<<endl;
            break;
        }
    }while(choice!=4);
    return 0;
}
