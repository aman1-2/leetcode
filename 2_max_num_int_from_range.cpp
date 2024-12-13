/**
 * Brute Force Approach - Used Vector, BinarySearch, sorting
 */
#include<iostream> 
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

//Searching an element in the array and returning its index position
int search(vector<int> &banned, int target) {
    int start = 0, stop = banned.size() -1;
    while(start <= stop) {
        int mid = start + (stop - start)/2;
        if(banned[mid] == target)   return mid;
        else if(banned[mid] < target)   start = mid+1;
        else    stop = mid-1;
    }
    return -1;
}

//Here we are returing the count of the elements that are not in the banned array and comes in 
//the range of 1 to n. Too making sure that the sum of the counted elements must not increase maxSum.
int maxCount(vector<int> &banned, int n, int maxSum) {
    //Ensuring that the elements must e already sorted before applying Binary Search.
    sort(banned.begin(), banned.end());
    //STEP 1: Made an vector ans to store the elements lying in the range 1 to n, and to ensuring that these elements 
    //don't exists in banned vector, and last condition checking that the sum of the counted integers sould be equal to or less than the maxSum.
    // vector<int> ans;

    int count = 0; //Instead of the vector we can to make a count variable which will count the number of elements presence.

    //STEP 2: Running a loop from 1 to n and checking if the element exists in the array or not.
    for(int i=1; i<=n; i++) {
        //STEP 3: If the element doesn't exist in the array we can consider it.
        if(-1 == search(banned, i)) {
            //STEP 4: If the value of i is less than maxSum in that case add that element in the ans vector.
            if(i <= maxSum){
                // ans.push_back(i);
                //And update the maxSum. As we have included that element hence the maxSum will reduce by that many times.
                
                //If the element satisfies all condition it will be included thus increasing the count.
                count++;
                maxSum -= i;
            }
        }
    }

    //STEP 5: At the end returning the size of the ans vector.
    return count;
}

/**
 * Optimize version - use a Hash Table -> set; vector; Binary Search; 
 */

int optimize(vector<int> &banned, int n, int maxSum) {
    //STEP 1: Create a set out of the banned vector.
    unordered_set<int> bannedSet(banned.begin(), banned.end());

    //STEP 2: Making a count variable to count the elements which we can include satisfying all the conditions.
    int count = 0;
    
    //STEP 3: Iterating the loop within the range 1 to n.
    for(int i=1; i<=n; i++) {
        if(!bannedSet.count(i)){
            if(i <= maxSum){
                maxSum -= i;
                count++;
            }
        }
    }

    //STEP 4: Return the value of the count.
    return count;

}

int main() {
    vector<int> banned = {1};
    int res = optimize(banned, 10000, 100000000);
    cout<<res<<endl;
    return 0;
}