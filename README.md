# TutorOnDemand Android App

This Android application, TutorOnDemand, facilitates the scheduling of tutorial sessions. Instructors can post tutorial topics, and students can express their interest by selecting a topic and a preferred date/time.

## Features

* **Topic Listing:** Displays a list of tutorial topics retrieved from Firebase Realtime Database.
* **Topic Details:** Allows students to view topic details, enter their name, and select a preferred date and time.
* **"Join" Functionality:** Enables students to "join" a topic, which increments the student count in Firebase.
* **Options Menu:** Includes an options menu with "Add Topic," "Settings," and "Refresh News" actions.
* **Settings:** Provides a settings screen (SettingsFragment) where users can toggle notifications.
* **News Feed:** Displays tutorial updates in a news feed format.
* **Firebase Integration:** Uses Firebase Realtime Database for real-time data storage and retrieval.
* **SQLite Caching:** Implements local caching of topics using SQLite for offline functionality.
* **SharedPreferences:** Persists user settings, such as notification preferences.
* **User Interface:** Employs Fragments, RecyclerView, CardView, DatePicker, TimePicker, and custom styles for an interactive and polished user experience.

## Technologies Used

* Android Studio
* Java
* Firebase Realtime Database
* SQLite
* SharedPreferences
* Fragments
* RecyclerView
* CardView
* DatePicker
* TimePicker
* AlertDialog

## Setup

1.  **Prerequisites:**
    * Android Studio installed with an emulator configured (e.g., Pixel 6, API 34).
    * A Google account for Firebase setup.
    * Basic knowledge of Android development (activities, layouts, Java/Kotlin).

2.  **Firebase Setup:**
    * Create a Firebase project in the Firebase Console ([https://console.firebase.google.com/](https://console.firebase.google.com/)).
    * Add your Android app to the Firebase project.
    * Download the `google-services.json` file and place it in your Android project's `app/` directory.
    * Add the necessary Firebase dependencies to your `build.gradle` (Module: app) file.

3.  **Project Setup in Android Studio:**
    * Clone the repository into Android Studio.
    * Build and run the application on an emulator or a physical device.

## Code Structure

The project is structured as follows:

* **`MainActivity`**: The main activity of the application, which hosts the fragments.
* **`activity_main.xml`**: Layout file for `MainActivity`, containing a `FrameLayout` to hold fragments.
* **`TopicListFragment`**: Fragment displaying the list of tutorial topics and the news feed.
* **`fragment_topic_list.xml`**: Layout file for `TopicListFragment`, containing a `RecyclerView` and a `TextView` for the news feed.
* **`TopicAdapter`**: Adapter for the `RecyclerView` in `TopicListFragment`, responsible for displaying topic items.
* **`item_topic.xml`**: Layout file for individual topic items in the `RecyclerView`, using `CardView`.
* **`Topic`**: Data class representing a tutorial topic.
* **`TopicDetailsFragment`**: Fragment displaying details of a selected topic and allowing students to join.
* **`fragment_topic_details.xml`**: Layout file for `TopicDetailsFragment`, containing `TextView`s, `EditText`, `DatePicker`, `TimePicker`, and a `Button`.
* **`SettingsFragment`**: Fragment for application settings, such as notification preferences.
* **`fragment_settings.xml`**: Layout file for `SettingsFragment`, containing a `Switch` for toggling notifications.
* **`topic_list_menu.xml`**: Menu resource file for the options menu in `TopicListFragment`.
* **`dialog_add_topic.xml`**: Layout file for the "Add Topic" dialog.

## Functionality

1.  **Topic List Fragment:**
    * Displays a list of topics fetched from Firebase in a `RecyclerView`.
    * Each topic is shown in a `CardView` with topic name, instructor, and a "Join" button.
    * Includes a news feed section to display tutorial updates.
    * Provides an options menu with "Add Topic," "Settings," and "Refresh News" options.

2.  **Topic Details Fragment:**
    * Displays the selected topic's details (name, instructor).
    * Allows students to enter their name and select a preferred date and time using `DatePicker` and `TimePicker`.
    * The "Join Topic" button increments the student count for the topic in Firebase.

3.  **Options Menu:**
    * **Add Topic:** Opens a dialog for instructors to add new tutorial topics.
    * **Settings:** Navigates to the `SettingsFragment` to manage application settings.
    * **Refresh News:** Refreshes the news feed with the latest updates from Firebase.

4.  **Firebase Integration:**
    * Real-time data storage and retrieval for topics and news feed.
    * Data is structured to allow easy management of topics and associated information.

5.  **SQLite Caching:**
    * Local caching of topic data to enable offline access.
    * Data synchronization when the device is online.

6.  **SharedPreferences:**
    * Stores user preferences, such as notification settings.

## Enhancements

* **UI/UX:** Improve the user interface with custom styles, themes, and drawables.
* **Error Handling:** Implement robust error handling and user feedback mechanisms.
* **Data Validation:** Add input validation to prevent invalid data entry.
* **Advanced Features:** Consider adding features like user authentication, push notifications, and more detailed scheduling options.

## Notes

* This project provides a basic framework for the TutorOnDemand application.
* Further development and refinement are encouraged to enhance functionality and user experience.
* Remember to test thoroughly, especially Firebase connectivity and SQLite fallback.
