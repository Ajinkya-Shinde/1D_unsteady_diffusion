clc
clear all

sol = csvread('solution_1d.csv');
sol = sol(3,1:end-1); %remove endline character

x = linspace(0,1,101);
% for t = 0:10:50 
% u = exp(-((2*pi)^2)*t/1000)*sin(2*pi*x);
% plot(x, u);
% hold on
% end

t = 0.05;
u = exp(-((2*pi)^2)*t)*sin(2*pi*x);
plot(x, u,'g-o');
hold on
plot(x, sol, 'r');