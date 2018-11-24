#include <iostream>
using namespace std;
int knapsack(int Weight[],int Value[],int Size,int Num);

int Size,Num;
int main()
{
    cout<<"�����뱳��������";
    cin>>Size;
    cout<<"�������װ����Ʒ������:";
    cin>>Num;
    int Weight[Num+1],Value[Num+1];

    for(int i=1;i<=Num;i++)
    {
        cout<<"�������"<<i<<"����Ʒ��"<<endl;
        cout<<"����:";
        cin>>Weight[i];
        cout<<"��ֵ:";
        cin>>Value[i];
    }
    knapsack(Weight,Value,Size,Num);

    return 0;

}


int knapsack(int Weight[],int Value[],int Size,int Num)
{
    int temp[Num+1][Size+1]={0};
    int jmin=min(Weight[1],Size);
    for(int j=0;j<jmin;j++)
    {
        temp[1][j]=0;
    }
    for(int j=Weight[1];j<=Size;j++)
    {
        temp[1][j]=Value[1];
    }
    for(int i=2;i<=Num;i++)
    {       jmin=min(Weight[i],Size);
            for(int j=0;j<jmin;j++)
            {
                temp[i][j]=temp[i-1][j];
            }
            for(int j=Weight[i];j<=Size;j++)
            {
                temp[i][j]=max(temp[i-1][j],temp[i-1][j-Weight[i]]+Value[i]);
            }

    }
    for(int i=1;i<=Num;i++)
    {

        for(int j=0;j<=Size;j++)
            cout<<temp[i][j]<<" ";
        cout<<endl;
    }
    cout<<"�������Ϊ��"<<temp[Num][Size]<<endl;
    cout<<"װ����Ʒ�ı��Ϊ��";
    int temp_Size=Size;
    for(int i=Num;i>=2;i--)
    {
        if(temp[i][temp_Size]!=temp[i-1][temp_Size])
        {
            cout<<i<<" ";
            temp_Size-=Weight[i];
        }
    }
    if(temp_Size>=Weight[1])
        cout<<"1 "<<endl;
}
