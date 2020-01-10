#include <bits/stdc++.h>
using namespace std;
int vx, vy, z, x, y;
int nstep ;
queue<int> trace;                                                                       // Lưu lại những lần đong nước vào bình X và bình Y.
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
void read() {
    cin >> vx >> vy >> z;
}
void solve() {
    // Nếu lượng nước cần đong không chia hết cho UCLN của thể tích bình X và Y thì không thể đong được.
    if(z % gcd(vx,vy) != 0){                                                            
        cout << "-1";
        return;
    }
    while(true){
        // Các luật dẫn xuất.
        // Nếu bình x còn có thể chứa nước được và cần đổ nước từ bình y qua.
        if(x < vx && y > 0 ){
            // Nếu lượng nước từ bình Y qua lớn hơn lượng nước bình x có thể chứa.
            if(y > vx-x){
                y -= (vx-x);                                                            // Phần nước còn lại trong bình Y sau khi đổ đầy bình X.
                x = vx;                                                                 // Bình X được đổ đầy nước.
            }
            else {
                x += y;                                                                 // Phần nước bình X được tăng lên.
                y = 0;                                                                  // Nước trong bình Y được đổ qua hết cho bình X.
            }
        }
        else {
            // Nếu thùng X đang đầy nước thì đổ hết nước trong bình X đi.
            if(x == vx) x = 0;
            // Nếu trong thùng Y không có nước thì đổ đầy nước vào bình Y.
            if(y == 0) y = vy;
        }
        // Thực hiện đong nước.
        nstep++;
        trace.push(x); trace.push(y);                                                   // Lưu những lần đong nước lại để khúc cuối in ra màn hình.

        // Thực hiện in ra màn hình nếu thỏa mãn điều kiện bài toán.
        if(x == z || y == z){                                                           // Nếu nước trong bình X hoặc trong bình Y bằng với số nước cần đong.
            cout << nstep << endl;                                                      // In ra số bước đã thực hiện.
            while(!trace.empty()){                                                      // In những lần đong nước đã thực hiện ra màn hình.
                cout << trace.front() ; trace.pop();
                cout << " " << trace.front(); trace.pop();
                cout << endl;
            }
            return;
        }
    }
}
int main()
{
    read();
    solve();
    return 0;
}
