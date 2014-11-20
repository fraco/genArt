#include "ofMain.h"

class genArt : public ofBaseApp{
    
public:
    
    ofPath path;
    
    int recursionLevel = 6;
    float startRadius = 300;
    
    float x, y, radius;
    int level;
    
    void drawBranch(float x, float y, float radius, int level)
    {

        path.clear();
        path.setStrokeColor(ofColor::blueSteel);
        path.setStrokeWidth(level*2);
        path.arc(x,y, radius,radius, -180, 0);

        path.draw();
        
        ofFill();
        ofSetColor(56);
        ofCircle(x, y, level*3);
        
        if (level > 0 ){
            drawBranch(x-radius, y+radius/2, radius/2, level-1);
            drawBranch(x+radius, y+radius/2, radius/2, level-1);
        }
//        return drawBranch(x, y, radius, level);
    }

    void setup(){
        path.setFilled(false);
        path.hasOutline();
        path.setArcResolution(120);
    }

    void draw(){
        
        ofBackground(ofColor::white);
        ofTranslate(ofGetWidth() / 2 , ofGetHeight() /2 );
        drawBranch(0, 0, startRadius, recursionLevel);
        ofFill();
        ofSetColor(0, 0, 255);
        
    };

    void keyReleased(int key){
        
        int k = int(key)-49;
        if (k>=0 && k<9) {
            recursionLevel = k;
        }
        
    }
    
};

//========================================================================
int main( ){
	ofSetupOpenGL(1200,1000,OF_WINDOW);			// <-------- setup the GL context
	ofRunApp(new genArt());

}
