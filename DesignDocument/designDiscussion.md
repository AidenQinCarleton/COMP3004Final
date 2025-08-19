# Design Discussion

This document discusses the design behind each class and how they interact with each other.

## Device
The device class is where the exam is taken. It will detect if user has skin contact with the device and send results back to the app accordingly.  

The device will maintain a connection with the app.

### Battery
The device will have a battery that will depleted over time. The battery status will be sent and able to be viewed on the app.

## App
The app will be used to control the device and view the results of the exam. The app will also maintain up to 5 user profiles. Each user profile will have a history of their exam results.

### Profile
The profile will store the user info such as name, gender, weight, height, birthday, phone number, and email. The profile will also store the user's exam history.

### ExamResult
The exam result will first be stored in the device and then sent to the app. The app will then store the exam result in the user's profile.

### Recommendation
The app will provide recommendations based on the exam results. 
The recommendation is currently a placeholder per the assignment requirements.

### User interface
The app will have a user interface that will allow the user to start an exam, view exam results, view recommendations, and view their profile.