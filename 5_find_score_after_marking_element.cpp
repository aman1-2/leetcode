/**
 * Medium - 2593
 * You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

Example 1:
Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.

Example 2:
Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

//This is Brute force approach ->
    //T.C - O(n.logn) - sorting taked O(n.logn) then we traverse one time whole sorted array which takes O(n) T.C.
    
    // long long findScore(vector<int>& nums) {
    //     int n = nums.size();
    //     long long score = 0; //For storing the value of the score.

    //     //STEP 1: Created another vector as sorted and marked where in the sorted vector we store the pairs of sorted elmenet with their old index value i.e. the original index value. Whereas the marked vector used for checking if we have already visited that index position in the old vector or not.
    //     vector<pair<int, int>> sorted(n);
    //     vector<bool>marked(n, false); //Inittialized the marked value as false in initial stage.

    //     //STEP 2: Storing the elements in the sorted array.
    //     for(int i=0; i<n; i++) {
    //         sorted[i] = make_pair(nums[i], i);
    //     }

    //     //STEP 3: Once we have added the element in the sorted array we can now just sort the array.
    //     sort(sorted.begin(), sorted.end());

    //     //STEP 4: Now we can traverse on each of the sorted value and see if they are not marked visited then we can add that value in the score and if marked visited skip and move to next one.
    //     for(int i=0; i<n; i++) {
    //         int number = sorted[i].first;
    //         int index = sorted[i].second;

    //         if(!marked[index]){
    //             score += number;
    //             marked[index] = true;
    //             //Now marking the adjacent element if they exists
    //             if(index - 1 >= 0)  marked[index - 1] = true;
    //             if(index + 1 < n)   marked[index + 1] = true;
    //         }
    //     }

    //     return score;
    // }