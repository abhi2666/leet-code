/* Find range sum in an array
--> you are given array and you have to find sum of the elements in a given
range(low, high).

Best Approach is the Segment Tree approach where you create a tree using the
given array where all array elements are on the leaf node and all internal 
nodes represent sum of elements in a range(l, r). 
*/
#include <iostream>
#include <vector>
using namespace std;

void buildSegTree(int a[], vector<int> &seg, int index, int low, int high)
{
    if(low == high)
    {
        seg[index] = a[low];
        return;
    }
    int mid = (low + high)/2;
    //now create left and right children
    buildSegTree(a, seg, 2*index + 1, low, mid); //left child
    buildSegTree(a, seg, 2*index + 2, mid + 1, high); //right child
}

int query(vector<int> seg, int index, int low, int high, int l, int r)
{
    if(low >=l && high <= r)
    {
        // fully overlapping
        return seg[index];
    }
    if(high < l || low > r) return 0;
    // for partially overlapping
    int mid = (low + high)/2;
    //move left and right  and take values that those left and right
    // gives you
    int left = query(seg, 2*index + 1, low, mid, l, r);
    int right  = query(seg, 2*index + 2, mid + 1, high, l, r);
    return (left+right);
    
}

int main()
{
    int n;cin>>n;
    int a[n];
    vector<int> seg(4*n, 0);
    for(int i = 0; i < n; i++) cin>>a[i];

    // build the ST(Segment Tree)
    buildSegTree(a, seg, 0, 0, n - 1); // (array, starting_index, final_index)
    // find range sum
    int l, r;
    cin>>l>>r;
    cout<<query(seg, 0, 0, n - 1, l, r)<<endl;
    return 0;
}