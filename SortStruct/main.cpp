#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct example
{
    int elem1;
    int elem2;
}example;

/**
升序排序,就是"<",降序排列就是">"号,这样便于直观记忆.
*/
bool comparison(example a,example b){
    return a.elem1<b.elem1;
}

int main()
{
    int N = 10;
    vector<example> array(N);
    for(int i=0;i<N;i++)
    {
        array[i].elem1 = random()%100;
        array[i].elem2 = random()%100;
        cout<<array[i].elem1<<","<<array[i].elem2<<endl;
    }
    cout<<endl<<endl;
    sort(array.begin(),array.end(),comparison);
    for(int i=0;i<N;i++)
    {
        cout<<array[i].elem1<<" "<<array[i].elem2<<endl;
    }
    return 0;
}
