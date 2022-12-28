#include <stdio.h>
#include <string.h>

int res=0,rec=0;
int recursion(const char *s, int l, int r){
    rec++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    
    int n;
    char s[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s);
        rec=0;
        res=isPalindrome(s);
        printf("%d %d\n",res,rec);
    }
    return 0;
}