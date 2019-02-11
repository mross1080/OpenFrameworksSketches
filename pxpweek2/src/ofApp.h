#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    void basicGrid();
    void drawWithTriangles();
    void drawWithSine();
    void drawRandomLines();
    void drawCircles();
    void drawCircles2();
    void rotateRectangles();
    
    
    void randomWithoutFlicker();
    float lastX, lastY;
    float randomXPositions[10000];
    float randomYPositions[10000];

    int count =0;
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
