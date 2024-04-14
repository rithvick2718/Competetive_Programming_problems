#include<bits/stdc++.h>
using namespace std;
struct finale
{
    int id;
    int p_solved;
    int score;
    bool operator< (const finale &F)
    {
        if(score!=F.score) return (score>F.score);
        else if( p_solved!=F.p_solved) return(p_solved>F.p_solved);
        else return(id<F.id);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N,T,P;
    cin>>N>>T>>P; //no choice
    int k; //help variable
    int Contestant[N][T+1]; //N is number of participants and T is for task Contestant[N][T] stores the number of questions solved
    int points[T]; //giving points for each task
    fill(points,points+T,N); //initially all points are N
    for (int i = 0; i < N; i++)
    {
        Contestant[i][T] =0;
        for (int j = 0; j < T; j++)
        {
            cin>>k; // this is 1 or 0 but i took int so that I don't get a weird error
            points[j]=points[j]-k; //understandable
            Contestant[i][j]=k; //the 2D array get's filled
            Contestant[i][T] =Contestant[i][T] +k;
        }
    }// all inputs taken and the points of each task
    vector<finale> data(N);
    for(int i=0; i<N;i++)
    {
        data[i].id=i+1;
        data[i].p_solved=Contestant[i][T];
        data[i].score =0;
        for(int j =0; j<T;j++)
        {
            data[i].score=data[i].score+(Contestant[i][j])*(points[j]);
        }
    }
    k=data[P-1].score;
    cout<<k<<" ";
    sort(data.begin(),data.end());
    //now comes the rubbish O(n) part
    for(int i=0; i<N;i++)
    {
        if(P==data[i].id)
        {
            cout<<i+1;
            break;
        }
    }
    return 0;
}