/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author eman
 */

// class representing a city node in the priority queue
class citynode implements Comparable<citynode> {
    int city; // the city index
    int days; // the number of days taken to reach this city

    public citynode(int city, int days) {
        this.city = city;
        this.days = days;
    }

    // compare method for priority queue to order by days
    @Override
    public int compareTo(citynode other) {
        return Integer.compare(this.days, other.days); // Compare based on days
    }
}