#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetCircleResolution(60);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofSeedRandom(39);

	auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
	auto base_deg = ofRandom(360);
	for (int radius = 160; radius <= 300; radius += 10) {

		ofPushMatrix();

		ofRotateZ(ofMap(ofNoise(noise_seed.z + radius * 0.002 + ofGetFrameNum() * 0.005), 0, 1, -200, 200));
		ofRotateY(ofMap(ofNoise(noise_seed.y + radius * 0.002 + ofGetFrameNum() * 0.005), 0, 1, -200, 200));
		ofRotateX(ofMap(ofNoise(noise_seed.x + radius * 0.002 + ofGetFrameNum() * 0.005), 0, 1, -200, 200));

		ofNoFill();
		ofSetColor(239);
		ofDrawCircle(glm::vec3(), radius);

		auto speed = 6;
		auto deg = base_deg + ofMap(radius, 160, 300, 0, 180);

		ofFill();
		ofSetColor(255, 0, 0);
		ofDrawSphere(
			glm::vec3(radius * cos((deg + ofGetFrameNum() * speed) * DEG_TO_RAD), radius * sin((deg + ofGetFrameNum() * speed) * DEG_TO_RAD), 0), 8);

		ofPopMatrix();
	}

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}