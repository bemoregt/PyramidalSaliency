#include "ofApp.h"

using namespace std;
using namespace cv;
using namespace ofxCv;

//------------------------------------------------------
// Function that returns harmonic mean.
int harmonicMean(vector<float> arr, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++){
        sum = sum + 1.0 / arr[i];
    }
    return (int)n/sum;
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    oled.load("/Users/kerbal/Desktop/bb.png");
    aa.load("/Users/kerbal/Desktop/s1.png");
    bb.load("/Users/kerbal/Desktop/s2.png");
    cc.load("/Users/kerbal/Desktop/s3.png");
    dd.load("/Users/kerbal/Desktop/s4.png");
    ee.allocate(aa.getWidth(), aa.getHeight(), OF_IMAGE_COLOR);
    //cc.load("/Users/kerbal/Desktop/low.png");
    
    for(int x=0; x<aa.getWidth(); x++){
        for(int y=0; y<aa.getHeight(); y++){
            ofColor c1 = aa.getColor(x, y);
            ofColor c2 = bb.getColor(x, y);
            ofColor c3 = cc.getColor(x, y);
            ofColor c4 = dd.getColor(x, y);
            
            vector<float> r, g, b;
            r.push_back(c1.r);
            r.push_back(c2.r);
            r.push_back(c3.r);
            r.push_back(c4.r);
            
            g.push_back(c1.g);
            g.push_back(c2.g);
            g.push_back(c3.g);
            g.push_back(c4.g);
            
            b.push_back(c1.b);
            b.push_back(c2.b);
            b.push_back(c3.b);
            b.push_back(c4.b);
            
            float harmonicR = harmonicMean(r, 4);
            float harmonicG = harmonicMean(g, 4);
            float harmonicB = harmonicMean(b, 4);
            //ofLog() << harmonicG;
            
            ee.setColor(x, y, ofColor(harmonicR, harmonicG, harmonicB));
            //cc.setColor(x, y, ofColor(harmonicG));
        }
    }// for x
    ee.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255);
    oled.draw(0, 0, 256, 256);
    aa.draw(256, 0, 256, 256);
    bb.draw(512, 0, 256, 256);
    cc.draw(0, 256, 256, 256);
    dd.draw(256, 256, 256, 256);
    if(cc.isAllocated()){
        ee.draw(512, 256, 256, 256);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
