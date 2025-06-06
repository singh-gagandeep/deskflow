/*
 * Deskflow -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2014 - 2016 Symless Ltd.
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#pragma once

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>

class DataDownloader : public QObject
{
  Q_OBJECT

public:
  explicit DataDownloader(QObject *parent = nullptr);
  ~DataDownloader() override = default;

  QByteArray data() const;
  void cancel();
  void download(QUrl url);
  bool isFinished() const
  {
    return m_IsFinished;
  }

Q_SIGNALS:
  void isComplete();

private Q_SLOTS:
  void complete(QNetworkReply *reply);

private:
  QNetworkAccessManager m_NetworkManager;
  QByteArray m_Data;
  QNetworkReply *m_pReply = nullptr;
  bool m_IsFinished = false;
};
