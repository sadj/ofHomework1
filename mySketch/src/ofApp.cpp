#include "ofApp.h"

//code below was based on part of this tutorial:  //github.com/mikewesthad/ofSite/blob/master/_tutorials/03_graphics/generativemesh.markdown
void ofApp::setup(){
    //ofPixels p;
    //ofLoadImage(p, "LewisHine.png");
    
    image.load("Dali.jpg");
    image.resize(100, 62);
    mesh.setMode(OF_PRIMITIVE_LINES);
    
    float intensityThreshold = 150.0;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x < w; ++x){
        for (int y=0; y < h; ++y ){
            ofColor c = image.getColor(x,y);
            float intensity = c.getLightness();
            if (c.getLightness() > intensityThreshold){
                ofVec3f pos(4*x, 4*y, 0.0);
                mesh.addVertex(pos);
                mesh.addColor(c);
            }
        }
    }
    
    float connectionDistance = 30;
    int numVerts = mesh.getNumVertices();
    for (int a = 0; a < numVerts; ++a){
        ofVec3f verta = mesh.getVertex(a);
        for (int b = a+1; b < numVerts; ++b){
            ofVec3f vertb = mesh.getVertex(b);
            float distance = verta.distance(vertb);
            if(distance <= connectionDistance){
                mesh.addIndex(a);
                mesh.addIndex(b);

            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    image.draw(0,0);
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(0,0,0);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
   
    
    easyCam.begin();
        ofPushMatrix();
            ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2);
             mesh.draw();
        ofPopMatrix();
    easyCam.end();
    
                
    

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
    
  
    
    cout << "vertices: " << mesh.getNumVertices() << endl;
    
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
