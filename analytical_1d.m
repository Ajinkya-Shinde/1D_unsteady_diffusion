clc
clear all

sol = csvread('solution_1d.csv');
sol = sol(:,1:end-1); %remove endline character

x = linspace(0,1,128);
% for t = 0:10:50 
% u = exp(-((2*pi)^2)*t/1000)*sin(2*pi*x);
% plot(x, u);
% hold on
% end

t=[0.0 0.001 0.005 0.01];
for i=1:1:4
u = exp(-((2*pi)^2)*t(i))*sin(2*pi*x);
figure(1)

subplot(2,2,i)
plot(x, u,'r-s','MarkerFaceColor','r','MarkerSize',10,'MarkerIndices',1:4:128);
hold on
plot(x, sol(i,:), 'g-o','MarkerFaceColor','g','MarkerIndices',1:4:128);
title(sprintf('Time steps = %d', t(i)*100000));
xlabel('x');
ylabel('u');
ylim([-1.2 1.2]);
legend('Analytical','Numerical');

end