syms Ts x1 x2 x3 theta w a
theta = 0;
Ts = 0.001;
x1 = 0; x2 = 0; x3 = 0;
%w = 2; a = 1.5;


A = [1 Ts*x3 Ts*x2; -Ts*x3 1 -Ts*x1; 0 0 0];
B = [Ts 0 0; 0 Ts 0; 0 0 1];
H = [cos(theta) sin(theta) -w*cos(theta)/2+a*sin(theta); cos(theta) sin(theta) w*cos(theta)/2+a*sin(theta); 1 0 -w/2; 1 0 w/2];
Q = [0.06 0 0;0 0.7 0;0 0 0.005];
R = [1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1];
P = [0.00001 0 0; 0 0.00001 0; 0 0 0.00001];
x = [x1; x2; x3];
z = [1; 1; 1; 1];
disp(x);



%for t=0:1
    x = A*x;
    P = A*P*A' + Q;
    K = P*H'/(H*P*H'+R);
    x = x + K*(z-H*x);
    P = (1-K*H)*P;
    disp(P);
    
%end



