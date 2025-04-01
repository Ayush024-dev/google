// qp link: https://leetcode.com/problems/find-median-from-data-stream/description/
/* problem description: The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted. */

// Approach is to maintain a multiset why? (because it always maintains a sorted order), insert element into the multiset and for median get the element at the middle of the multiset. If the size is even, take the 
// average of the current mid and the prev pointer values and return it. But it's not that easily as it sounds. You cannot point iterator anywhere except begin() or end(), in O(1) time. For other position, you need to 
// iterate to that position and place a pointer there after initializing it with st.begin(). So that means for every find median call you iterate to the mid pointer again and again. Not efficient right. 

//So what now? One thing is sure, that we need to iterate the pointer to the mid position as there is no other way, and if we need to do that, then why not iterate it alongside inserting of numbers. Let's take an example
// First I have my multiset okay...now I need to insert 1 into my st. So I name an iterator of the type multiset and point the iterator it to st.begin(). 
// so now it points to -> 1 and multiset={1}, now if I need median, I will just return *(it) right...
// now I insert 2 into my multiset, so multiset={1,2} it->1, median = (1+2)/2= 1.5, but how to get this via this pointer it? 
// either I take the average of current value of it and next(it), or increase it and take the average of curr value of it and
// prev(it). Anyways I'll get my answer. Let's increase it for now, so now it points to it->2. Multiset is {1,2}.
// Now I insert 3 in the multiset, so multiset={1,2,3} it->2, which is median. Now if I insert 4 and increase it
// multiset={1,2,3,4} and it ->3 and I can calculate median based to the even formula. Main point to note is, whenever after
// inserting an element if the size of multiset is even, move it ahead, for calculation. But if it is odd then, keep it in the 
//same place right? UMM...no why?
// okay let's insert -1 into my multiset, what does happen now? multiset st={-1, 1, 2, 3, 4} and where does it points? it points to
// it->3. Remember it is a pointer which points a position not number. So what happenend? Ans should be 2, but as per it value
//it's 3 which is wrong. So there is another condition. if the size is odd and the inserted number is less than the number in the it,
// then move it back, because the length at the back has increased and therefore your it isn't pointing to the median (when the size is odd).
// hope so the explaination is clear. Please provide your feedback or ask any doubts in the comment section. I'll see you in the next question.
// below is the code:-
class MedianFinder {
public:
    multiset<int> st;
    multiset<int>::iterator it;

    MedianFinder() : it(st.end()) {}

    void addNum(int num) {
        st.insert(num);

        // Case 1: First element inserted, set iterator to begin()
        if (st.size() == 1) {
            it = st.begin();
        } 
        // Case 2: Odd -> Even: Move right
        else if (st.size() % 2 == 0) {
            if (num >= *it) ++it;
        } 
        // Case 3: Even -> Odd and inserted value<*it -> Move left
        else {
            if (num < *it) --it;
        }
    }

    double findMedian() {
        if (st.size() % 2 != 0) return *it;

        auto before = prev(it); // Get element before `it`
        return (*it + *before) / 2.0;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
