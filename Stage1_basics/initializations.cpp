/* So we have different kinds of variable initializaions in c++. 
I am wondering which one to use. Perhaps inspecting their assembly part is useful.
*/

#include <iostream>

int main() {
    int var1 = 10;
    int var2 (20);
    int var3 {30}; //this guy is better, less error prone
    int var4 = {40};
    int var5 {}; //worked
    int var6 = {}; //worked
    // int var7 = (); //this is syntax error
    //int var6(); --> this gives us compile warning: empty parentheses were disambiguated as a function declaration
    //now pointer?
    int *var7;
    int *var8 = nullptr;
    int *var9 {};
    int *var10();
    // int *var11 = ();//syntax error

    std::cout << var1 << " " << var2 << " " << var3 << " " << var4 << std::endl;

    return 0;
}
/*
.LC0:
        .string " "
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 48
        mov     DWORD PTR [rbp-4], 10
        mov     DWORD PTR [rbp-8], 20
        mov     DWORD PTR [rbp-12], 30
        mov     DWORD PTR [rbp-16], 40
        mov     DWORD PTR [rbp-20], 0
        mov     DWORD PTR [rbp-24], 0
        mov     QWORD PTR [rbp-32], 0
        mov     QWORD PTR [rbp-40], 0
        mov     eax, DWORD PTR [rbp-4]
        mov     esi, eax
        mov     edi, OFFSET FLAT:std::cout
        call    std::ostream::operator<<(int)
        mov     esi, OFFSET FLAT:.LC0
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     rdx, rax
        mov     eax, DWORD PTR [rbp-8]
        mov     esi, eax
        mov     rdi, rdx
        call    std::ostream::operator<<(int)
        mov     esi, OFFSET FLAT:.LC0
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     rdx, rax
        mov     eax, DWORD PTR [rbp-12]
        mov     esi, eax
        mov     rdi, rdx
        call    std::ostream::operator<<(int)
        mov     esi, OFFSET FLAT:.LC0
        mov     rdi, rax
        call    std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)
        mov     rdx, rax
        mov     eax, DWORD PTR [rbp-16]
        mov     esi, eax
        mov     rdi, rdx
        call    std::ostream::operator<<(int)
        mov     esi, OFFSET FLAT:std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)
        mov     rdi, rax
        call    std::ostream::operator<<(std::ostream& (*)(std::ostream&))
        mov     eax, 0
        leave
        ret

*/


//So, about variables, how about type conversions? Oh yeah, this is important.
