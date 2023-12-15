#include <stdio.h>

typedef struct {
  int order_id;
  char nama_kasir[101];
  int tgl;
  int bln;
  int thn;
  int jumlah_produk;
  char nama_makanan [20];
  char nama_minuman [20];
  float harga;
  float total;
}database;

float harga_total (float n) {
  float a;
  a = n + (n * 0.11);
  return a;
}

int main() {
  database cafe [100];
  int jenis;
  float harga_total_before_tax;
  int main_menu;
  FILE *fp;
  
  printf("------------\n");
  printf("   Le cafe  \n");
  printf("------------\n");
  printf("\n");
  printf("1. Entry Sales\n");
  printf("2. Lihat transaksi penjualan\n");
  printf("3. Cari berdasarkan nama\n");
  printf("4. Cari berdasarkan kisaran harga\n");
  printf("5. Cari berdasarkan stok\n");
  printf("6. Cari berdasarkan yang sudah terjual\n");
  printf("7. Keluar\n");

  
  printf("Pilih Menu: ");
  scanf("%d", &main_menu);
  getchar ();

  switch (main_menu){
    case 1: {
      int entry_menu;
      int idx;
      fp = fopen ("Sales.txt","a+");
      
      if (fp == NULL) {
      	printf ("File not found!!!!");
      	return 0;
	  }
      printf ("transaksi ke : ");
      scanf("%d",&idx);
      
      cafe[idx].order_id = idx;
      getchar ();
	     
      printf("Cashier Name: ");
      scanf("%[^\n]",cafe[idx].nama_kasir);

      printf("Date of transaction: ");
      scanf("%d",&cafe[idx].tgl);

      printf("Month of transaction: ");
      scanf("%d",&cafe[idx].bln);

      printf("Year of transaction: ");
      scanf("%d",&cafe[idx].thn);

      printf("Number of product: ");
      scanf("%d",&cafe[idx].jumlah_produk);

      printf ("Type of purchase\n");
      printf ("1. Makanan\n");
      printf ("2. Minuman\n");
      printf ("Type of purchas: ");
      scanf("%d",&jenis);
      getchar ();

      if (jenis == 1) {

        printf("Name of food: ");
        scanf("%[^\n]",cafe[idx].nama_makanan);

        printf("Price of food: ");
        scanf("%f",&cafe[idx].harga);

        harga_total_before_tax = cafe[idx].jumlah_produk * cafe[idx].harga;

        cafe[idx].total = harga_total(harga_total_before_tax);

        fprintf (fp,"%d %s %d/%d/%d %d Makanan %s %.3f %.3f\n",cafe[idx].order_id,cafe[idx].nama_kasir,
          cafe[idx].tgl,cafe[idx].bln,cafe[idx].thn,cafe[idx].jumlah_produk,
          cafe[idx].nama_makanan,cafe[idx].harga,cafe[idx].total); 
      }
      else if (jenis == 2){

        printf("Name of drink: ");
        scanf("%s",cafe[idx].nama_minuman);

        printf("Price of drink: ");
        scanf("%f",&cafe[idx].harga);

        harga_total_before_tax = cafe[idx].jumlah_produk * cafe[idx].harga;

        cafe[idx].total = harga_total(harga_total_before_tax);

        fprintf (fp,"%d %s %d/%d/%d %d Minuman %s %.3f %.3f\n",cafe[idx].order_id,cafe[idx].nama_kasir,
          cafe[idx].tgl,cafe[idx].bln,cafe[idx].thn,cafe[idx].jumlah_produk,
          cafe[idx].nama_minuman,cafe[idx].harga,cafe[idx].total);
      } 
      fclose (fp);
      break;
    }
    case 2: {
      int view_menu;
      fp = fopen ("Sales.txt","r"); //??menurutku tiap case dibukanya
      printf("1. Tanggal transaksi\n");
      printf("2. Harga\n");
      printf("3. Stok\n");
      printf("4. Paling sering terjual\n");
  
      printf("Masukan pilihan: ");
      scanf("%d", &view_menu);

      switch(view_menu){
        case 1: {
          int tanggal_menu;
          printf("Tampilkan tanggal transaksi dari: \n");
          printf("1. Baru ke lama\n");
          printf("2. Lama ke baru\n");
          printf("Masukan pilihan: ");
          scanf("%d", &tanggal_menu);

          switch (tanggal_menu) {
            case 1: {
              
            }
            case 2: {
              
            }
          }
        }
        case 2: {
          int harga_menu;
          printf("Tampilkan harga dari: \n");
          printf("1. Termurah ke termahal\n");
          printf("2. Termahal ke termurah\n");
          printf("Masukan pilihan: ");
          scanf("%d", &harga_menu);

          switch (harga_menu) {
            case 1: {
              
            }
            case 2: {
              
            }
          }
        }
        case 3: {
          int stok_menu;
          printf("Tampilkan stok dari: \n");
          printf("1. Paling banyak");
          printf("2. Paling sedikit");
          printf("Masukan pilihan: ");
          scanf("%d", &stok_menu);

          switch (stok_menu) {
            case 1: {
              
            }
            case 2: {
              
            }
          }
        }
        case 4: {
          //langsung keluar sort terjual, dari yang paling bnyk ke sedikit
        }
      }
    }
    
    case 3: {
    	char search[101];
		int i = 0;
		fp = fopen("Sales.txt", "r");
		
		if (fp == NULL) {
        	printf("File not found or could not be opened.\n");
        	return 1;
		}
		
		printf("Masukan Nama: ");
		scanf("%[^\n]", search);
		
		while (fscanf(fp, "%d %s %d/%d/%d %d       %s %.3f %.3f",&cafe[i].order_id,cafe[i].nama_kasir,
          &cafe[i].tgl,&cafe[i].bln,&cafe[i].thn,&cafe[i].jumlah_produk,
          cafe[i].nama_makanan,&cafe[i].harga,&cafe[i].total) != EOF) {

	        if (strcmp(cafe[i].nama_makanan, search) == 0) {
	            printf("Nama ditemukan pada order id nomor %d.\n", i);
	            break;
	        }
	
	        i++;
		}
		
		if (feof(fp)) {
        printf("Nama tidak ditemukan dalam data.\n");
		}

    fclose(fp);
    break;
    }

    case 4: {
    	float search;
		int i = 0;
		fp = fopen("Sales.txt", "r");
		
		if (fp == NULL) {
    		printf("File not found or could not be opened.\n");
    		return 1;
		}
		
		printf("Masukan Harga yang Dicari: ");
		scanf("%f", &search);
		
		while (fscanf(fp, "%d %s %d/%d/%d %d       %s %.3f %.3f",&cafe[i].order_id,cafe[i].nama_kasir,
          &cafe[i].tgl,&cafe[i].bln,&cafe[i].thn,&cafe[i].jumlah_produk,
          cafe[i].nama_makanan,&cafe[i].harga,&cafe[i].total) != EOF) {
			if (cafe[i].harga == search) {
    			printf("Harga ditemukan pada order id nomor %d.\n", i);
        		break;
    		}
		i++;
		}
		if (feof(fp)) {
			printf("Harga tidak ditemukan dalam data.\n");
		}
		
		fclose(fp);
    }

    case 5: {
      
    }

    case 6: {
      
    }

    case 7: {
		return 0; 
    }
}
return 0;

}
