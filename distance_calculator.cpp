#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

// फैक्ट्री/बायोगैस प्लांट का स्ट्रक्चर
struct Factory {
    string name;
    double latitude;
    double longitude;
};

// दो पॉइंट्स के बीच की हवाई दूरी निकालने का फंक्शन
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // हावरसाइन फॉर्मूला (Haversine Formula) का इस्तेमाल
    return sqrt(pow(lat2 - lat1, 2) + pow(lon2 - lon1, 2)) * 111.0; // 111 किमी प्रति डिग्री (सरल रूप में)
}

int main() {
    cout << "--- कृषि-उन्नति AI: C++ फास्ट डिस्टेंस कैलकुलेटर ---" << endl;

    // किसान की लोकेशन (मान लेते हैं अमृतसर के पास)
    double farmerLat = 31.6340;
    double farmerLon = 74.8723;

    // कुछ बायोगैस प्लांट्स और फैक्ट्रियों का डेटाबेस
    vector<Factory> factories = {
        {"ऊर्जा फ्लो बायोगैस प्लांट", 31.5200, 75.1000},
        {"ग्रीन टेक रीसाइक्लिंग", 31.3256, 75.5792},
        {"पंजाब बायो-फ्यूल्स", 30.9010, 75.8573}
    };

    string nearestFactory = "";
    double minDistance = 99999.0;

    // C++ की सुपर-फास्ट लूपिंग से सबसे नजदीकी प्लांट ढूंढना
    for (const auto& factory : factories) {
        double dist = calculateDistance(farmerLat, farmerLon, factory.latitude, factory.longitude);
        cout << factory.name << " की दूरी: " << dist << " किमी" << endl;

        if (dist < minDistance) {
            minDistance = dist;
            nearestFactory = factory.name;
        }
    }

    cout << "\n[RESULT] किसान के सबसे नजदीक फैक्ट्री है: " << nearestFactory << endl;
    cout << "कुल दूरी: " << minDistance << " किमी" << endl;

    return 0;
}