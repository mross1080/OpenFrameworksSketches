#include "ofApp.h"
int xPos = 0;
//--------------------------------------------------------------
void ofApp::setup(){
     ofSetFrameRate(100);
    xPos = 5;  // horizontal start position
//    ofBackground(ofColor::red);  // black background
    ofSetBackgroundAuto(false);
    
    // We still want to draw on a black background, so we need to draw
    // the background before we do anything with the brush
    ofBackground(0);
    
//    for (int i = 0; i < 10000; i++) {
//
//        randomXPositions[i] = ofRandom(ofGetWidth());
//        randomYPositions[i] = ofRandom(ofGetHeight());
//        
//    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    xPos += 2;
    if(ofGetWidth()<xPos){  // if horizontal position is off the screen (width)
        xPos = 5;             // reset horizontal position
    }
//    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::draw(){
//    basicGrid();
//    drawWithTriangles();
//    drawWithSine();
//    drawRandomLines();
//    drawCircles2();
//    rotateRectangles();
    randomWithoutFlicker();
    
    
    
//    ofDrawRectangle(xPos, 200,200,200);
//    ofSetColor(ofColor::red);  // draw everything in red
//    ofDrawCircle(xPos, 100, 10);
//    int randomSeedColor = ofRandom(120,255);
//    ofSetColor(ofRandom(0,255));
//    ofSetRectMode(OF_RECTMODE_CENTER);
//    for(int x =0; x < ofGetWidth(); x=  x +40) {
//    for(int y =0; y < ofGetHeight(); y = y +20) {
//         ofSetColor(ofGetMouseX()/2,randomSeedColor,100);  // draw everything in red
//
////         ofSetColor(ofColor::red);  // draw everything in red
//         ofDrawRectangle(x, ofRandom(0,ofGetHeight()), 20, 10);
////
//    }
//    }
//    ofDrawRectangle(ofGetMouseX(), ofGetMouseY(), 50, 50);  // Draw a 50 x 50 rect
}

//--------------------------------------------------------------


void ofApp::basicGrid() {
    int cellSize = 20;
    ofBackground(255);
    for(int x =0; x < ofGetWidth(); x+=cellSize) {
        for(int y =0; y < ofGetHeight(); y+=cellSize) {
 
            ofSetColor(x,ofGetSeconds()*2,ofGetMouseX());
            ofDrawRectangle(x,y,cellSize,cellSize);
        }
        
    }
}

void ofApp::drawWithTriangles() {
    int cellSize = 20;
    ofBackground(0);
    for(int x =0; x < ofGetWidth(); x+=cellSize) {
        for(int y =0; y < ofGetHeight(); y+=cellSize) {
            ofPushMatrix();
            float distanceToMouse =  ofDist(x,y,ofGetMouseX(),ofGetMouseY());

            ofTranslate(x,y);
            ofRotateDeg(distanceToMouse/5);
            ofDrawTriangle(-cellSize/2, -cellSize/2, -cellSize/2,cellSize/2, cellSize/2, cellSize/2);
            ofPopMatrix();
            
        }
        
    }
}


void  ofApp::randomWithoutFlicker() {
    int cellSize = 20;
//    ofBackground(0);
    for(int x =0; x < 10000; x+=5) {
        float xPosition = ofRandom(10000);
        float yPosition = randomYPositions[x];
        ofSetColor(xPosition/4,yPosition/4,ofGetMouseX()/4);
        ofSetLineWidth(1);
        
        ofDrawRectangle(xPosition,yPosition,cellSize,cellSize);


        
    }
    
}

int count = 0;
void  ofApp::drawWithSine() {
    int cellSize = 10;
    ofBackground(0);
    for(int x =0; x < ofGetWidth(); x+=cellSize) {
        for(int y =0; y < ofGetHeight(); y+=cellSize) {
            float distanceToMouse =  ofDist(x,y,ofGetMouseX(),ofGetMouseY());
            distanceToMouse+= count;
            distanceToMouse/= 30;
            float newGray = ofMap(sin(distanceToMouse),-1,1,0,255);
            ofSetColor(newGray);
            ofDrawRectangle(x,y,cellSize,cellSize);
        }
        
    }
    
}

void  ofApp::drawRandomLines() {
    int cellSize = 10;
    ofBackground(0,0,255,5);

    ofNoFill();
//    ofSetColor(255, 0, 0);//stroke color
    for(int x =0; x < 1000; x+=10) {
        float thisX = ofGetMouseX() + ofRandom(-x, x);
        float thisY = ofGetMouseY() + ofRandom(-x, x);
        ofDrawLine(thisX, thisY, lastX, lastY);
        lastX = thisX;
        lastY = thisY;
   
        
    }
    ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
}

void ofApp::drawCircles() {
    ofBackground(255);
    int cellSize =40;
    for(int x =0; x < 1000; x+=cellSize) {
for(int y =0; y < ofGetHeight(); y+=cellSize) {
        float distanceToMouse =  ofDist(x,y,ofGetMouseX(),ofGetMouseY());

        ofPushMatrix();
        ofTranslate(0,0,distanceToMouse);
        ofSetColor(distanceToMouse); //fill color
      ofDrawEllipse(x,y,cellSize*2,cellSize*2);
    ofPopMatrix();

        
        
}}
    
    
}


void ofApp::rotateRectangles() {

//    ofLightsData();
    ofBackground(0);
    int cellSize =50;
    for(int x =0; x < ofGetWidth(); x+=cellSize) {
        for(int y =0; y < ofGetHeight(); y+=cellSize) {
            float distanceToMouse =  ofDist(x,y,ofGetMouseX(),ofGetMouseY()) ;
            
            ofPushMatrix();
            ofTranslate(x,y);
//            ofSetColor(distanceToMouse);
            ofRotateX(distanceToMouse/100.00);

            ofDrawRectangle(0,0,cellSize,cellSize);
            
            
            
            ofPopMatrix();
            
            
            
        }}
    
    
}

void ofApp::drawCircles2() {
    if (count > 10) {
        
        count = 0;
        
    }
    count++;
//    count =5;
    
    ofBackground(255);
    int cellSize =30;
    for(int x =0; x < ofGetWidth(); x+=cellSize) {
        for(int y =0; y < ofGetHeight(); y+=cellSize) {
            float distanceToMouse =  ofDist(x,y,ofGetMouseX(),ofGetMouseY()) ;
            
            ofPushMatrix();
            ofTranslate(0,0,distanceToMouse);
            ofSetColor(distanceToMouse);
//            ofSetColor(count*10,distanceToMouse,distanceToMouse); //fill color
//            ofDrawRectangle(x,y,cellSize*2,cellSize*2);
            ofDrawRectangle(x,y,cellSize*count,cellSize*count);

            ofRotateDeg(count);
//            ofDrawRectangle(x,y,count*2,count*2);
            ofPopMatrix();
            
            
            
        }}
    
    
}

void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    ofDrawRectangle(x, y,200,200);
//    ofSetColor(ofColor::red);  // draw everything in red

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
