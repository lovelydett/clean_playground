package com.lovelydett.app;

import java.util.List;

public class VendingMachine {
    private List<Product> products;
    private Display display;
    private CoinSlot coinSlot;
    
    // A constructor that takes the above resources
    public VendingMachine(List<Product> products, Display display, CoinSlot coinSlot) {
        this.products = products;
        this.display = display;
        this.coinSlot = coinSlot;
    }

    // show the available products and their prices
    public void showProducts() {
        for (Product product : products) {
            display.showMsg(product.getName() + " " + product.getPrice());
        }
    }

    // user select a product
    public Product selectProduct(int choice) {
        if (choice < 1 || choice > products.size()) {
            display.showMsg("Invalid choice");
            return null;
        }
        Product product = products.get(choice - 1);
        display.showMsg("You selected " + product.getName());
        return product;
    }

    // do purchase
    public void purchase(Product product, int payment) {
        if (payment < product.getPrice()) {
            display.showMsg("Not enough money");
            coinSlot.returnCoins(payment);
        }
        int change = payment - product.getPrice();
        display.showMsg("Here is your change " + change);
        coinSlot.returnCoins(change);
    }
}
