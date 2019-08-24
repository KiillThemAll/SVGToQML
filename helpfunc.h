#ifndef HELPFUNC_H
#define HELPFUNC_H

#include <QRegularExpression>
#include <QStringList>

inline void getNumberFromQString(const QString &xString, QStringList &nums)
{
  QRegularExpression re("(-?\\d+(?:[\\.,]\\d+(?:e\\d+)?)?)");
  QRegularExpressionMatchIterator i = re.globalMatch(xString);

  while (i.hasNext()) {
      QRegularExpressionMatch match = i.next();
      QString num = match.captured(1);
      nums << num;
  }
}

#endif // HELPFUNC_H
