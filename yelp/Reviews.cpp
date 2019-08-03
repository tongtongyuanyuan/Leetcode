//
// Created by Tong Xue on 7/4/19.
//

//1.输入1: map { topic: [ keyword1, keyword2 ... ] }.
//  输入2: list of customer reviews 
//输出: map {topic: int}，其中int是numbef of reviews in which the topic occur 
//其中所有keyword都是小写。 reviews会有大写 ,keyword可能由多个word组成。
//example: input: 
//  map = {  price: ['cheap', 'expensive', 'discount']    
//         location: ['near', 'far', 'busy']    
//          Burger King: ['burger king'] } 
//reviews = [ 
//            'It is a cheap one comparing to all the restaurants near me.', 
//            'I would rather go to Burger King since they always have a discount, while the original price is
//             'It is so expensive and the traffic around it is always busy! This will be the last time I come!' 
//           ] 
//output: 
// {
//     price: 3
//    location: 2 
//    Burger King: 1 
// }


#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <unordered_set>
#include <sstream>

using namespace std;

bool isAlpha(char& ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}



//reviews = [ "ab cd eg! fg, hi."]
//reviews = [ "ab cd eg  fg  hi "]

//reviews >> vector<string>


unordered_map<string, int> customerReviews(unordered_map<string, vector<string>>& input, vector<string>& reviews) {
    unordered_map<string, int> count;

    unordered_map<string, string> key_topic;
    for(auto &it: input) {
        for (auto &keywords : it.second) {
            key_topic[keywords] = it.first;
        }
    }

    for (string &p : reviews) {
        for (char &ch : p) {
            ch = isAlpha(ch) ? tolower(ch) : ' ';
        }
    }

    for (string &r : reviews) {
        //r >> "ab cd eg  fg  hi ";
        istringstream str(r);
        string tmp;
        while(str >> tmp){
            if(key_topic.count(tmp))
                count[key_topic[tmp]]++;
        }
    }

    return count;
}


int main() {
    unordered_map<string, vector<string>> input{
            {"price", {"cheap", "expensive", "discount"}},
            {"location", {"near", "far", "busy"}},
            {"Burger King", {"burger" ,"king"}}
    };

    vector<string> reviews;
    reviews.emplace_back("It is a cheap one comparing to all the restaurants near me.");
    reviews.emplace_back("I would rather go to Burger King since they always have a discount, while the original price is");
    reviews.emplace_back("It is so expensive and the traffic around it is always busy! This will be the last time I come!");

    auto res = customerReviews(input,reviews);
    for(auto &r : res) {
        cout << setw(12) << r.first << " : " << r.second << endl;
    }

}



