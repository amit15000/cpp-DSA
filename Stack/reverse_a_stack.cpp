// 2.0

// void insertAtBottom(stack<int> &stack, int target) {
//   if (stack.empty()){
//     stack.push(target);
//     return;
//     }
//     int temp = stack.top();
//     stack.pop();
//     insertAtBottom(stack, target);
//     stack.push(temp);
// }
// void reverseStack(stack<int> &stack) {
//     if(stack.empty())
//         return;

//     int target=stack.top();
//     stack.pop();
//     reverseStack(stack);
//     insertAtBottom(stack,target);

// }