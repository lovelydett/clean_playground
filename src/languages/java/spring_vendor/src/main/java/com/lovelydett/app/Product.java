package com.lovelydett.app;

public class Product {
    private String name;
    private int price;

    // constructor
    public Product(String name, int price) {
        this.name = name;
        this.price = price;
    }

    // getter
    public String getName() {
        return name;
    }

    // getter
    public int getPrice() {
        return price;
    }
}
