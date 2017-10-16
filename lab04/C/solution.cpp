#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

int T, i, j, n, flag = 0;
char in_char;
int main(){
    scanf("%d", &T);
    stack<int> stack_;
    for(i = 0;i<T;i++){
        flag = 0;
        //scanf("%d", &n);
        cin >> n;
        //printf("n: %d",n);
        if(n%2==1){
            printf("NO\n");
            for(j=0;j<n;j++){
                cin >> in_char;
            }
        }else{
            for(j=0;j<n;j++){
                cin >> in_char;
                //printf("input char %c , %d\n",in_char, flag);
                if(in_char == '(' || in_char=='{' || in_char == '['){
                    stack_.push(in_char);
                }else{
                    if(stack_.empty()){
                        flag = 1;
                        break;
                    }else{
                        switch(in_char){
                            case ')':
                                if(stack_.top() != '(')
                                    flag = 1;
                                    break;
                            case ']':
                                if(stack_.top() != '[')
                                    flag = 1; 
                                    break;
                            case '}':
                                if(stack_.top() != '{')
                                    flag = 1;
                                    break;
                            default:
                                flag = 1;
                        }
                        if(flag){
                            break;
                        }else{
                            stack_.pop();
                        }
                    }
                }
            }
            if(flag){
                printf("NO\n");
                for(;j<n;j++){
                    getchar();
                }
            }else{
                printf("YES\n");
            }
            
        }
    }
    return 0;
}