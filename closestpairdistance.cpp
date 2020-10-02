#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Point{
public:
    int x,y;

};
//sqrt(pow(p1.x-p2.x,2)+ pow(p1.y-p2.y,2))
float distanc(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+ (p1.y-p2.y)*(p1.y-p2.y));
}
int compareX(const void* a,const void* b){
    Point *p1=(Point *)a,*p2=(Point *)b;
    return(p1->x - p2->x);
}
int compareY(const void* a,const void* b){
    Point *p1=(Point *)a,*p2=(Point *)b;
    return(p1->y - p2->y);
}
float findiny(Point p[20],float mini,int n){
    Point strip[20];
    int k=0;
    float miniy=mini;
    for(int i=0;i<n;i++){
        if(abs(p[n/2].x-p[i].x)<=mini)
            strip[k++]=p[i];
        else if(p[i].x-p[n/2].x>mini)
            break;
    }
    qsort(p,n,sizeof(Point),compareY);
    for(int i=0;i<(sizeof(strip)/sizeof(strip[0]));i++){
        if(miniy>distanc(strip[i],strip[i+1])){
            miniy=distanc(strip[i],strip[i+1]);
        }
    }
    return miniy;
}
float findmin(Point p[20],int n){
    qsort(p,n,sizeof(Point),compareX);
    float mini=distanc(p[0],p[1]);
    for(int i=1;i<n/2;i++){
        if (mini>distanc(p[i],p[i+1]))
            mini=distanc(p[i],p[i+1]);
    }
    for(int i=n/2;i<n;i++){
        if (mini>distanc(p[i],p[i+1]))
            mini=distanc(p[i],p[i+1]);
    }
    return findiny(p,mini,n);
}
int main()
{
    int n;
    Point p[20];
    cout<<"Enter number of points"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        p[i].x=a;
        p[i].y=b;
    }
    cout<<findmin(p,n)<<endl;
    return 0;
}
