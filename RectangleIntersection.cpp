#include<bits/stdc++.h>
using namespace std;
typedef struct rectangle{
    int x, y;
    int width, height;
    // int top, bottom, left, right;
}Rect;

bool IsIntersect(const Rect & r1, const Rect & r2) {
    return r1.x<=r2.x+r2.width&&r1.x+r1.width>=r2.x&&r1.y<r2.y+r2.height&&r1.y+r1.height>=r2.y;
}

Rect InsertRectangle(const Rect & r1, const Rect & r2) {
    if(!IsIntersect(r1,r2)){
        return Rect{0,0,-1,-1};
    }
    return Rect{max(r1.x,r2.x),max(r1.y,r2.y), min(r1.x+r1.width,r2.x,r2.width)-max(r1.x,r2.x),min(r1.y+r1.height,r2.y+r2.height)-max(r1.y,r2.y)};
}

int main(void) {

    return 0;
}