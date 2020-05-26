% f1 = @(x, xdata) x(1)*xlogx(xdata) + x(2)*xdata;
% f2 = @(x, xdata) x(1)*xdata;
% f3 = @(x, xdata) x(1)*log(xdata) + x(2);
% x01 = [0.001, 0.001];
% x02 = [0.001];
% x03 = [1, 3];
% xdata1 = rdx(:, 3); ydata1 = rdx(:, 1);
% xdata2 = mrgi(:, 3); ydata2 = mrgi(:, 1);
xdata3 = mrgr(:, 3); ydata3 = mrgr(:, 4);
xdata4 = qs1rRAND(:, 3); ydata4 = qs1rRAND(:, 4);
xdata5 = qs2rRAND(:, 3); ydata5 = qs2rRAND(:, 4);
xdata6 = qsfpRAND(:, 3); ydata6 = qsfpRAND(:, 4);
% xdata7 = stlRAND(:, 3); ydata7 = stlRAND(:, 1);
% fit1 = lsqcurvefit(f2, x02, xdata1, ydata1)
% fit2 = lsqcurvefit(f1, x01, xdata2, ydata2)
% fit3 = lsqcurvefit(f3, x03, xdata3, ydata3)
% fit4 = lsqcurvefit(f3, x03, xdata4, ydata4)
% fit5 = lsqcurvefit(f3, x03, xdata5, ydata5)
% fit6 = lsqcurvefit(f3, x03, xdata6, ydata6)
% fit7 = lsqcurvefit(f1, x01, xdata7, ydata7)
% fit8 = lsqcurvefit(f3, x03, xdata1, ydata1);
figure
hold on
% plt1 = plot(xdata1, ydata1);
% pltfit1 = plot(xdata1, f2(fit1, xdata1), 'LineWidth', 2);
% pltfit2 = plot(xdata2, f1(fit2, xdata2), 'LineWidth', 2);
plt3 = plot(xdata3, ydata3, 'LineWidth', 2);
% pltfit3 = plot(xdata3, f3(fit3, xdata3), 'LineWidth', 2);
plt4 = plot(xdata4, ydata4, 'LineWidth', 2);
% pltfit4 = plot(xdata4, f3(fit4, xdata4), 'LineWidth', 2);
plt5 = plot(xdata5, ydata5, 'LineWidth', 2);
% pltfit5 = plot(xdata5, f3(fit5, xdata5), 'LineWidth', 2);
plt6 = plot(xdata6, ydata6, 'LineWidth', 2);
% pltfit6 = plot(xdata6, f3(fit6, xdata6), 'LineWidth', 2);
% pltfit7 = plot(xdata7, f1(fit7, xdata7), 'LineWidth', 2);
grid on;
title('Comparação do número de chamadas recursivas');
xlabel('Tamanho do vetor');
ylabel('Chamadas');
legend([plt3, plt4, plt5, plt6],{'Merge recursivo', 'Quicksort 1 recursão', 'Quicksort 2 recursões', 'Quicksort pivô fixo'}, 'Location', 'northwest');
