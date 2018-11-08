#include "search.h"

using namespace std;

/* Binary Search implementation
name: binary_Search
input: vector<int> array, int key, int low, int high
output: pair<bool, int> indicating the status of search and position if successful else -1
*/
pair<bool,int> binary_search(vector<int> array, int key, int low, int high)
{
    int mid = (low+high)/2;
    if(low>high)
        return make_pair(false,-1);
    else if(array[mid]==key)
        return make_pair(true,mid);
    if(array[mid]<key)
        return binary_search(array,key,mid+1,high);
    return binary_search(array,key,low,mid-1);
}

/* Linear Search implementation
name: linear_search
input: vector<int> array, int key
output: pair<bool, int> indicating the status of search and position if successful else -1
*/
pair<bool,int> linear_search(vector<int> array, int key)
{
    for(auto it=array.begin();it!=array.end();it++)
        if(*it==key)
            return make_pair(true,(int)distance(array.begin(),it));
    return make_pair(false,-1);
}


