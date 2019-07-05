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
//}
