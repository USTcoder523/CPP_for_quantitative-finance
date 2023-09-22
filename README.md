# Pricing and modelling derivatives in C++
1.Black-Scholes and Pricing Fundamentals<br>
2.Monte Carlo Simulation<br>
3.Binomial Trees<br>
4.Exotic Options<br>
5.Stochastic Volatility(Implied Volatility, Jump Diffusion Model...)


## The QuantLib Library ##
The example of a library that is used in quantitative finance and options analysis is the QuantLib library. QuantLib is a well-established repository of quantitative code for C++. The library has been tested and used by many developers, which means that you can take advantage of the hard work that went into creating and testing the algorithms.<br />

Being an open source project, QuantLib is free and can be used by anyone by just downloading and building the source code. The project also accepts contributed code, which means that many people can fix bugs and participate in the improvement of the library.<br />

The QuantLib contains a wide assortment of classes that simplify certain tasks that are necessary in quantitative algorithms for finance. A few areas covered by QuantLib are the following:<br />

- Date handling: Many algorithms for options and derivatives analysis are based on dates. Therefore, accurate information about trading dates, holidays, and other calendar-specific events are very important for the correct results of such algorithms. QuantLib provides a number of classes that encapsulate the concepts needed for data handling in financial applications.

- Design patterns: The QuantLib library puts a lot of effort in following well-established design patterns. Most algorithms use design patterns that make them easier to understand and to maintain. For this reason, QuantLib has a rich implementation of common design patterns, including Singleton, Observer, Composite, and others.
- Monte Carlo methods: A few of the classes provided by QuantLib
are used to simplify the implementation of Monte Carlo methods. These classes make it easier to create, for example, random paths for financial instruments, as well as similar models based on Brownian motion.
- Pricing engines: Another area that is covered by QuantLib is
the implementation of efficient pricing engines for options and derivatives. The library provides several techniques for options pricing, which are carefully packaged into C++ classes. These pricing engines include barrier option engines, Asian option engines, basket option engines, and vanilla option engines.
- Optimizers: Another utility that is frequently employed in financial applications is an optimization engine. The QuantLib library contains a few classes dedicated to some common optimization strategies. Using such optimization algorithms, it is possible to quickly solve complex problems where the objective is to find the minimum or the maximum of a given function.

 
by Jack YU
