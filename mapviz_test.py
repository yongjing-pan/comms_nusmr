import mapviz

# Rover's coordinates (latitude, longitude)
rover_lat = 1.3521  # Example latitude (Singapore)
rover_lon = 103.8198  # Example longitude

# Create a map and add a marker
mapviz.map(
    center=(rover_lat, rover_lon),
    zoom=15,
    tiles="satellite",  # Use "satellite" for a satellite view
    markers=[(rover_lat, rover_lon, "Rover")],
).show()
