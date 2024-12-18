/**
 * Easy
You are given an integer array prices where prices[i] is the price of the ith item in a shop.
There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j 
is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

Example 1:
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation: 
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.

Example 2:
Input: prices = [1,2,3,4,5]
Output: [1,2,3,4,5]
Explanation: In this case, for all items, you will not receive any discount at all.

Example 3:
Input: prices = [10,1,1,6]
Output: [9,0,1,6]

Constraints:
1 <= prices.length <= 500
1 <= prices[i] <= 1000
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    //STEP 1: Created a variable n in which storing the count of the Prices vector size and an ans vector because at the end we need to return a vector which has the final price of the items.
    int n = prices.size();
    vector<int> ans(n);

    //STEP 2: Since we need to calculate the final price of each item therefore need to traverse at least once to each item therefore an outer for loop which runs n times where n is the prices of n items in the vector. 
    for(int i=0; i<n; i++) { //T.C - O(n)
        bool flag = false; //Created a flag variable to ensure that for the item we have calculated the final price that is discount was given or not if not given then the original price will only go in the ans vector for that item as no discount was there for that item.

        //STEP 3: An inner for loop which too almost runs n times as we need to find out the dicount for each item.
        //And the conditions for finding the discounts are:- (i) jth index must be smaller then ith index and (ii) the price present at the jth index must be either small or equal to j. If this condition is true update the price.
        for(int j=i+1; j<n; j++) {
            if(prices[j] <= prices[i]) { //Condition matches
                ans[i] = (prices[i] - prices[j]); //Update the price
                // ans.push_back(prices[i] - prices[j]);
                flag = true; //Updated flag value as price was updated.
                break; //Breaking the loop as once we have calculated our new price no need of further looping and searching.
            }
        }

        //STEP 4: If somehow the value was not updated in the inner for loop and flag remains false then need to store the original price value in the vector.
        if(!flag) {
            ans[i] = prices[i];
            // ans.push_back(prices[i]);    
        }
    }

    //STEP 5: At the end returning the ans vector;
    return ans;
}

int main() {
    vector<int> prices = {8,4,6,2,3};
    vector<int> ans = finalPrices(prices);
    
    for(int ele: ans) {
        cout<<ele<<", ";
    }
    
    return 0;
}