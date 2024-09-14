#ifndef NETWORKAUTOCONNECTOR
#define NETWORKAUTOCONNECTOR
#include <string>

namespace io_github_pumpkinxd_ZitNetworkAutoConnector
{

class NetworkAutoConnector
{
  public:
    NetworkAutoConnector();
    NetworkAutoConnector(const std::string &filename);
    void saveConfig2file(const std::string &filename);
    bool isOnline();
    void updateOnlineStats();
    void updatePubkeyFromPortal();
    void fetchPortalUrlAndQuery();

    std::string getpublicKeyExponent();
    std::string getpublicKeyModulus();

  private:
    std::string PortalUrl;
    std::string QueryString;

    std::string userId;
    std::string EncryptedPWD;
    bool online;
    int zit_online;//0==not zit network; -1==zit network without login; 1==onlline; 2==unknown

    /***
     * seems they (zit) not changing their Network RSA key pair at all
     *
     * <code> 
     *  {
     *
     *           "publicKeyExponent":"10001",
     *           "publicKeyModulus":"94dd2a8675fb779e6b9f7103698634cd400f27a154afa67af6166a43fc26417222a79506d34cacc7641946abda1785b7acf9910ad6a0978c91ec84d40b71d2891379af19ffb333e7517e390bd26ac312fe940c340466b4a5d4af1d65c3b5944078f96a1a51a5a53e4bc302818b7c9f63c4a1b07bd7d874cef1c3d4b2f5eb7871"
     *  }
     *  </code>
     *
     *
     */

    std::string publicKeyExponent; // dec
    std::string publicKeyModulus;  // hex
};

} // namespace io_github_pumpkinxd_ZitNetworkAutoConnector

#endif /* NETWORKAUTOCONNECTOR */
