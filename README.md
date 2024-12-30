# Playlist Description

This playlist organizer takes in a CSV file in the format of dataset.csv and organizes the songs in an optimized way. 

---

## Table of Contents

- [About the Project](#about-the-project)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

---

## About the Project

This project was inspired by my personal experience of spending countless hours creating road trip playlists in Excel, meticulously crafting the perfect flow of energy and mood for each journey. I wanted to automate this process and develop a program that could replicate this kind of playlist curation with precision and creativity.

The program accepts a CSV file (`dataset.csv`) containing detailed song attributes, including artist, album, track name, popularity, danceability, energy, and more. From this data, a subset of key attributes is used to calculate an energy value for each song, which serves as the foundation for playlist organization.

### Key Features:
- **Energy-Based Organization**: The playlist begins with songs of the highest energy and progressively transitions to lower energy levels. This creates a dynamic and intentional listening experience.
- **Probability-Driven Transitions**: The program uses a probability distribution to decide whether the next song in the playlist increases, decreases, or maintains the current energy level. At the start, the probability of higher energy transitions is greater, but this shifts over time to favor lower energy levels.
- **Diverse Listening**: To ensure variety, songs by the same artist are not placed consecutively unless absolutely necessary.

### Subset of Attributes Used:
- **Danceability**: Suitability for dancing, ranging from 0.0 (least danceable) to 1.0 (most danceable).
- **Energy**: Intensity and activity of the track, measured from 0.0 to 1.0.
- **Loudness**: Overall loudness in decibels (dB).
- **Acousticness**: Confidence measure of whether the track is acoustic, ranging from 0.0 to 1.0.
- **Valence**: Musical positiveness, with higher values indicating a happier tone.
- **Tempo**: Speed or pace of the track, measured in beats per minute (BPM).
- **Popularity**: A score between 0 and 100, representing the track's overall popularity.
- **Mode**: The modality of the track, where 1 indicates major and 0 indicates minor.

This project transforms playlist creation into an intelligent and efficient process, delivering a smooth energy flow and an engaging listening experience. It’s a perfect blend of automation and artistry, inspired by my passion for road trips and music curation.

---

## Features

- **Automated Playlist Creation**: The program automates the process of crafting playlists by analyzing key song attributes and organizing tracks for an optimal listening experience.
- **Energy-Based Organization**: Songs are ordered to start with high energy levels, progressively transitioning to lower energy, creating a smooth and intentional energy flow throughout the playlist.
- **Probability-Driven Transitions**: The selection of the next song is based on a probability distribution:
  - Higher energy transitions are favored at the beginning.
  - Over time, the probability of transitioning to lower energy levels increases.
  - A balance of energy is maintained for a varied yet cohesive experience.
- **Artist Variety**: Ensures that consecutive songs by the same artist are avoided unless necessary, promoting diversity in the playlist.
- **Customizable Dataset**: Accepts a CSV file (`dataset.csv`) containing detailed attributes for each song, including:
  - Danceability, Energy, Loudness, Acousticness, Valence, Tempo, Popularity, Mode, and more.
- **Efficient and Scalable**: Designed to handle datasets of varying sizes, making it suitable for both small personal collections and large datasets.

---

## Installation

To set up the project locally, follow these steps:

1. **Clone the repository**  
   Use the following command to clone the repository to your local machine:
   ```bash
   git clone https://github.com/juliakpvelloso/PlaylistOrganizer.git
2. **Navigate to the project directory** 
    cd PlaylistOrganizer 
3. **Compile and Run the Program**
    make 
    ./playlist <INPUT.csv>

### Contributions 
Contributions are welcome! Please fork the repository and create a pull request. 

## Acknowledgments

This project was made possible with the help of the following resources:

- **[Kaggle](https://www.kaggle.com/)**: The `dataset.csv` file and detailed information about the column names were sourced from Kaggle. Their platform provided invaluable resources for this project.
